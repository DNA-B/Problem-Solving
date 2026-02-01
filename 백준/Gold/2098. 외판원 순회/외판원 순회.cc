#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>

using namespace std;

//========= MACRO =========//
#define PI 3.1415926535897932
#define INF 0x3f3f3f3f
#define LL_INF 1e18
#define ll long long
#define X first
#define Y second
//=========================//

//======= VARIABLEs =======//
int N;
int W[16][16];
int mem[1 << 16][16]; // { 방문한 도시 집합, i번 도시에 있을 때 최소 비용 }
//=========================//

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG

	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
			cin >> W[i][j];
	}

	for (int i = 0; i < (1 << N); i++) {
		for (int j = 0; j < N; j++)
			mem[i][j] = INT_MAX;
	}

	mem[1][0] = 0; // 어디서 시작하든 상관 X -> 지금은 0번부터 시작
	for (int mask = 1; mask < (1 << N); mask++) {
		for (int cur = 0; cur < N; cur++) {
			if (mem[mask][cur] == INT_MAX)
				continue;

			for (int next = 0; next < N; next++) {
				if (!W[cur][next]) // 경로 없음
					continue;
				if (mask & (1 << next)) // 이미 방문
					continue;

				int nxt_mask = mask | (1 << next);
				if (mem[nxt_mask][next] > mem[mask][cur] + W[cur][next])
					mem[nxt_mask][next] = mem[mask][cur] + W[cur][next];
			}
		}
	}

	// 다시 0번으로 돌아가는 비용 계산
	int res = INT_MAX;
	int total = (1 << N) - 1;
	for (int i = 1; i < N; i++) {
		if (W[i][0] && mem[total][i] != INT_MAX) // // i번 도시에서 0번으로 돌아오는 길이 있다면
			res = min(res, mem[total][i] + W[i][0]);
	}

	cout << res;
}