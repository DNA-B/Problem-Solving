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
int R, C;
char board[25][25];
set<string> dict;
//=========================//

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG

	cin >> R >> C;

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++)
			cin >> board[i][j];
	}

	for (int i = 0; i < R; i++) {
		string tmp = "";
		for (int j = 0; j < C; j++) {
			if (board[i][j] == '#') {
				if (tmp.size() >= 2)
					dict.insert(tmp);
				tmp = "";
				continue;
			}

			tmp += board[i][j];
		}

		if (tmp.size() >= 2)
			dict.insert(tmp);
	}

	for (int i = 0; i < C; i++) {
		string tmp = "";
		for (int j = 0; j < R; j++) {
			if (board[j][i] == '#') {
				if (tmp.size() >= 2)
					dict.insert(tmp);
				tmp = "";
				continue;
			}

			tmp += board[j][i];
		}

		if (tmp.size() >= 2)
			dict.insert(tmp);
	}

	cout << *dict.begin();
}