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
unordered_map<string, string> dict;
//=========================//

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG

	cin >> N;

	string s, tmp;
	for (int i = 0; i < N; i++) {
		cin >> s;

		tmp = s;
		if (s.size() > 2)
			sort(tmp.begin() + 1, tmp.end() - 1);

		dict[tmp] = s;
	}

	cin >> M;

	for (int i = 0; i < M; i++) {
		cin >> s;

		if (s.size() > 2)
			sort(s.begin() + 1, s.end() - 1);

		cout << dict[s] << (i == M - 1 ? "" : " ");
	}
}