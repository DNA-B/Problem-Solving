#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

/******** MACRO ********/
#define INT_INF 0x3f3f3f3f
#define LL_INF 1e18
#define MOD 1'000'000'007
#define PI 3.1415926535897932
#define ll long long
#define X first
#define Y second
/***********************/

/****** VARIABLEs ******/
int N;
stack<int> st;
/***********************/

int main() {
	cin.tie(NULL)->ios_base::sync_with_stdio(false);
	// freopen("input.txt", "r", stdin);

	cin >> N;

	for (int i = 1; i <= N; i++) {
		int x;
		cin >> x;

		if (st.empty()) {
			st.push(x);
			continue;
		}

		while (!st.empty() && x != st.top()) {
			cout << i << " ";
			st.pop();
		}
		st.push(x);
	}

	while (!st.empty()) {
		cout << -1 << " ";
		st.pop();
	}

	return 0;
}