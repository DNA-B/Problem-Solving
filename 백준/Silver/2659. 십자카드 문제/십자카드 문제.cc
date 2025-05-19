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
string S;
set<string> clock_nums;
//=========================//

void solve(string cur) {
	if (cur.size() == 4) {
		string mn = cur, tmp = cur;
		for (int i = 0; i < 4; i++) {
			rotate(tmp.begin(), tmp.begin() + 1, tmp.end());
			mn = min(mn, tmp);
		}
		clock_nums.insert(mn);
		return;
	}

	for (int i = 1; i <= 9; i++)
		solve(cur + to_string(i));
}

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG

	for (int x, i = 0; i < 4; i++) {
		cin >> x;
		S += to_string(x);
	}

	string mn = S, tmp = S;
	for (int i = 0; i < 4; i++) {
		rotate(tmp.begin(), tmp.begin() + 1, tmp.end());
		mn = min(mn, tmp);
	}

	solve("");
	auto it = clock_nums.find(mn);
	cout << distance(clock_nums.begin(), it) + 1;
}