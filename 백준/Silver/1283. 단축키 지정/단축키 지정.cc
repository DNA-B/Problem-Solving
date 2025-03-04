#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
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
int brackets[35];
bool vis[26];
string ops[35];
//=========================//

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG

	cin >> N; cin.ignore();
	fill(brackets, brackets + N, -1);

	for (int i = 0; i < N; i++) {
		getline(cin, ops[i]);

		for (int j = 0; j < ops[i].size(); j++) {
			if (ops[i][j] == ' ')
				continue;

			int idx = tolower(ops[i][j]) - 'a';
			if ((j == 0 || ops[i][j - 1] == ' ') && !vis[idx]) {
				vis[idx] = true;
				brackets[i] = j; // i번째 명령어의 단축키 인덱스
				break;
			}
		}

		if (brackets[i] != -1)
			continue;

		for (int j = 0; j < ops[i].size(); j++) {
			if (ops[i][j] == ' ')
				continue;

			int idx = tolower(ops[i][j]) - 'a';
			if (!vis[idx]) {
				vis[idx] = true;
				brackets[i] = j; // i번째 명령어의 단축키 인덱스
				break;
			}
		}
	}

	for (int i = 0; i < N; i++) {
		if (brackets[i] == -1) {
			cout << ops[i] << '\n';
			continue;
		}

		for (int j = 0; j < ops[i].size(); j++) {
			if (j == brackets[i]) cout << '[' << char(ops[i][j]) << ']';
			else cout << ops[i][j];
		}

		cout << '\n';
	}
}