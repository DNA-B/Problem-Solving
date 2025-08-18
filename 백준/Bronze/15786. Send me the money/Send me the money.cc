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
int N, M;
string mem;
//=========================//

bool check(string s) {
	int idx = 0;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == mem[idx])
			idx++;
		if (idx == mem.length())
			return true;
	}

	return false;
}

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG

	cin >> N >> M >> mem;

	string tmp;
	for (int i = 0; i < M; i++) {
		cin >> tmp;
		cout << (check(tmp) ? "true" : "false") << '\n';

	}
}