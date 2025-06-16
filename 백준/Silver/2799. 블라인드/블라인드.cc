#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#include <unordered_set>
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
int M, N;
int cnt[5];
char board[505][505];
vector<string> blind_type[5] = {
	{"....", "....", "....", "...."},
	{"****", "....", "....", "...."},
	{"****", "****", "....", "...."},
	{"****", "****", "****", "...."},
	{"****", "****", "****", "****"}
};
//=========================//

void check(int x, int y) {
	vector<string> blind;

	x *= 5, y *= 5;
	for (int i = x + 1; i < x + 5; i++) {
		string tmp = "";
		for (int j = y + 1; j < y + 5; j++)
			tmp += board[i][j];
		blind.push_back(tmp);
	}

	int idx = find(blind_type, blind_type + 5, blind) - blind_type;
	if (idx < 5)
		cnt[idx]++;
}

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG

	cin >> M >> N;

	for (int i = 0; i < 5 * M + 1; i++) {
		for (int j = 0; j < 5 * N + 1; j++)
			cin >> board[i][j];
	}

	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++)
			check(i, j);
	}

	for (int i = 0; i < 5; i++)
		cout << cnt[i] << ' ';
}