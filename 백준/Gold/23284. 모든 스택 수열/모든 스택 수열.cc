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
int N;
set<vector<int>> s;
//=========================//

void solve(int idx, vector<int> v, stack<int> st) {
	if (v.size() + st.size() == N) {
		while (!st.empty()) {
			v.push_back(st.top());
			st.pop();
		}

		s.insert(v);
		return;
	}

	// 1. pop후에 push
	if (!st.empty()) {
		int x = st.top();
		v.push_back(x);
		st.pop();
		solve(idx, v, st);
		st.push(x); // idx - 1  -> 복구
		v.pop_back();
	}

	st.push(idx);
	solve(idx + 1, v, st);
	return;
}

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG

	cin >> N;
	solve(1, {}, {});

	for (vector<int> v : s) {
		for (int x : v)
			cout << x << ' ';
		cout << '\n';
	}
}