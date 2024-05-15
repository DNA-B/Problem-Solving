#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

/******** MACRO ********/
#define BOUND 1001
#define MAX 1'000'000'001
#define MOD 10000
#define ll long long
#define X first
#define Y second
/***********************/

using namespace std;

/****** VARIABLEs ******/
int N, M;
char board[BOUND][BOUND];
int p[BOUND * BOUND];
int cur, nxt, cnt = 0;
/***********************/

int uf_find(int x) {
	if (p[x] < 0)
		return x;

	return p[x] = uf_find(p[x]);
}

bool uf_union(int a, int b) {
	a = uf_find(a);
	b = uf_find(b);

	if (a == b) // cycle 발생
		return false;

	if (p[a] == p[b])
		p[a]--;

	if (p[a] < p[b])
		p[b] = a;
	else
		p[a] = b;

	return true;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	// freopen("input.txt", "r", stdin);

	cin >> N >> M;

	fill(p, p + (N * M + 1), -1);

	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> board[i][j];

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			switch (board[i][j]) {
				case 'D':
					nxt = ((i + 1) * M) + j;
					break;
				case 'U':
					nxt = ((i - 1) * M) + j;
					break;
				case 'L':
					nxt = (i * M) + (j - 1);
					break;
				case 'R':
					nxt = (i * M) + (j + 1);
					break;
			}

			cur = (i * M) + j; // 유니온-파인드를 원할하게 수행하기 위하여 2차원을 1차원으로 표현

			if (!uf_union(cur, nxt)) // false면 cycle이 발생한 것
				cnt++;
		}
	}

	cout << cnt;

	return 0;
}