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
int N, x, last, res = 0;
stack<pair<int, int>> st;
/***********************/

int main() {
	cin.tie(NULL)->ios_base::sync_with_stdio(false);
	// freopen("input.txt", "r", stdin);

	cin >> N;

	for (int i = 0; i <= N; i++) {
		if (i < N)
			cin >> x;
		else if (i == N) // 맨 마지막에 남은 높이들 털기
			x = -1;

		last = i;
		while (!st.empty() && st.top().X > x) {
			last = st.top().Y;
			res = max(res, st.top().X * (i - last));
			st.pop();
		}
		st.push({ x, last });
	}

	cout << res;
	return 0;
}