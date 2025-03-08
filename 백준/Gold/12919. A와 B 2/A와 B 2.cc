#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#include<unordered_set>
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
string A, B;
unordered_set<string> dict;
//=========================//

void solve(string cur) {
	if (cur == A) {
		cout << 1 << "\n";
		exit(0);
	}

	if (A.size() >= cur.size())
		return;

	string tmp = cur;
	if (cur[cur.size() - 1] == 'A') {
		tmp.erase(--tmp.end());
		solve(tmp);
	}

	tmp = cur;
	if (cur[0] == 'B') {
		tmp.erase(tmp.begin());
		reverse(tmp.begin(), tmp.end());
		solve(tmp);
	}
}

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG

	cin >> A >> B;
	solve(B);
	cout << 0;
}