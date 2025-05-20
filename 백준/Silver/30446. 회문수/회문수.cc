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
ll N;
set<ll> pals;
//=========================//

bool is_pal(string s) {
	for (int i = 0; i < s.size() / 2; i++)
		if (s[i] != s[s.size() - (i + 1)])
			return false;
	return true;
}

void solve(string cur) {
	if (cur.size() > 0) {
		string tmp = cur; // 짝수 자리수 팰린드롬
		reverse(tmp.begin(), tmp.end());
		pals.insert(stoll(cur + tmp));

		tmp = cur.substr(0, cur.size() - 1); // 홀수 자리수 팰린드롬
		reverse(tmp.begin(), tmp.end());
		pals.insert(stoll(cur + tmp));

		if (is_pal(cur)) pals.insert(stoll(cur));
	}


	if (cur.size() == 5)
		return;

	for (int i = 0; i <= 9; i++) {
		if (i == 0 && cur == "") continue;
		solve(cur + to_string(i));
	}
}

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG

	cin >> N;
	solve("");
	auto it = upper_bound(pals.begin(), pals.end(), N);
	cout << distance(pals.begin(), it);
}