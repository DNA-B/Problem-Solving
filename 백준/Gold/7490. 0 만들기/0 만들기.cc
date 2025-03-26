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
int T, N;
vector<string> res;
//=========================//

void solve(int total, int sign, int cur, int idx, string exp) {
	if (idx == N) {
		total += (cur * sign);
		if (total == 0) res.push_back(exp);
		return;
	}

	solve(total + (cur * sign), 1, idx + 1, idx + 1, exp + '+' + to_string(idx + 1));
	solve(total + (cur * sign), -1, idx + 1, idx + 1, exp + '-' + to_string(idx + 1));
	solve(total, sign, stoi(to_string(cur) + to_string(idx + 1)), idx + 1, exp + ' ' + to_string(idx + 1));
}

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG

	cin >> T;

	while (T--) {
		cin >> N;

		res.clear();
		solve(0, 1, 1, 1, "1");

		sort(res.begin(), res.end());
		for (string s : res)
			cout << s << '\n';
		cout << '\n';
	}
}