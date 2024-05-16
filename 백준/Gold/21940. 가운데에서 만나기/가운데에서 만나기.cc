#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

/******** MACRO ********/
#define BOUND 205
#define MAX 1'000'000'001
#define MOD 10000
#define ll long long
#define X first
#define Y second
/***********************/

using namespace std;

/****** VARIABLEs ******/
const int INF = 0x3f3f3f3f;
int N, M, K; // 도시, 도로, 인원
int min_round_trip;
int d[BOUND][BOUND];
int hometown[BOUND]; // 살고 있는 도시
int round_trip[BOUND]; // 각 도시별 왕복 시간의 최댓값
/***********************/

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	// freopen("input.txt", "r", stdin);

	cin >> N >> M;

	for (int i = 1; i <= N; i++)
		fill(d[i], d[i] + (N + 1), INF);

	while (M--) {
		int a, b, t;

		cin >> a >> b >> t;
		d[a][b] = min(d[a][b], t);
	}

	for (int i = 1; i <= N; i++) // 자기 자신으로 가는 거리 0
		d[i][i] = 0;

	for (int k = 1; k <= N; k++)
		for (int i = 1; i <= N; i++)
			for (int j = 1; j <= N; j++)
				d[i][j] = min(d[i][j], d[i][k] + d[k][j]); // (i -> j) 거리와 (i -> k -> j) 거리 비교

	cin >> K; // 총 인원 수

	for (int i = 1; i <= K; i++)
		cin >> hometown[i];

	for (int i = 1; i <= N; i++) // 도시
		for (int j = 1; j <= K; j++) // hometown
			round_trip[i] = max(round_trip[i], d[hometown[j]][i] + d[i][hometown[j]]);

	min_round_trip = *min_element(round_trip + 1, round_trip + (N + 1));

	for (int i = 1; i <= N; i++) {
		if (round_trip[i] == min_round_trip)
			cout << i << " ";
	}

	return 0;
}