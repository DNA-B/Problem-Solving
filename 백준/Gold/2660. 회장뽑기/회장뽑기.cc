#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

/******** MACRO ********/
#define BOUND 60
#define MAX 1'000'000'001
#define MOD 10000
#define ll long long
#define X first
#define Y second
/***********************/

using namespace std;

/****** VARIABLEs ******/
const int INF = 0x3f3f3f3f;
int N, M;
int chairman_score = INT_MAX, chairman_cnt = 0;
int d[BOUND][BOUND];
int score[BOUND];
vector<int> res;
/***********************/

int main() {
	cin.tie(0)->sync_with_stdio(0);

	// freopen("input.txt", "r", stdin);

	cin >> N;

	for (int i = 1; i <= N; i++)
		fill(d[i], d[i] + (N + 1), INF);
	
    for (int i = 1; i <= N; i++)
		d[i][i] = 0;
    
	while (true) {
		int a, b;
		cin >> a >> b;

		if (a == -1 && b == -1) 
            break;

		d[a][b] = 1;
		d[b][a] = 1;
	}

	for (int k = 1; k <= N; k++)
		for (int i = 1; i <= N; i++)
			for (int j = 1; j <= N; j++)
				d[i][j] = min(d[i][j], d[i][k] + d[k][j]);

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (i == j) 
                continue;      
			score[i] = max(score[i], d[i][j]); // d의 max 값이 제일 마지막에 알게 된 친구이다.
		}
		chairman_score = min(chairman_score, score[i]);
	}

	for (int i = 1; i <= N; i++) {
		if (score[i] == chairman_score) {
			res.push_back(i);
			chairman_cnt++;
		}
	}

	cout << chairman_score << " " << chairman_cnt << '\n';

	for (auto chairman : res)
		cout << chairman << " ";

	return 0;
}