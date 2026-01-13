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
int N, M;
ll alp[26];
char board[105][105];
//=========================//

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++)
			cin >> board[i][j];
	}

	for (int i = 0; i < 2 * N; i++) {
		for (int j = 0; j < 2 * M; j++) {
			if (board[i][j] == '\0')
				board[i][j] = board[i % N][j % M];
		}
	}

	for (int i = 0; i < 2 * N; i++) {
		for (int j = 0; j < 2 * M; j++)
			alp[board[i][j] - 'A'] += (i + 1LL) * (2 * N - i) * (j + 1) * (2 * M - j);
	}

	for (int i = 0; i < 26; i++)
		cout << alp[i] << '\n';
}