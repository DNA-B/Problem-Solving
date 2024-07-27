#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

using namespace std;

/******** MACRO ********/
#define INF 0x3f3f3f3f
#define LLINF 1e18
#define MOD 1'000'000'007
#define PI 3.1415926535897932
#define ll long long
#define X first
#define Y second
/***********************/

/****** VARIABLEs ******/
int N, x;
vector<int> v;
stack<pair<int, int>> st; // { value, idx }
/***********************/

int main() {
	cin.tie(NULL)->ios_base::sync_with_stdio(false);
	// freopen("input.txt", "r", stdin);

	cin >> N;
	v.resize(N, -1);

	for (int i = 0; i < N; i++) {
		cin >> x;

		if (st.empty())
			st.push({ x, i });

		while (!st.empty() && st.top().X < x) {
			v[st.top().Y] = x;
			st.pop();
		}

		st.push({ x, i });
	}

	for (auto item : v)
		cout << item << " ";

	return 0;
}