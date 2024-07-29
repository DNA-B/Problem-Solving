#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stack>

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
int N, x, cnt;
ll res = 0;
stack<pair<int, int>> st;
/***********************/

int main() {
	cin.tie(NULL)->ios_base::sync_with_stdio(false);
	// freopen("input.txt", "r", stdin);

	cin >> N;

	while (N--) {
		cin >> x;

		cnt = 1;
		while (!st.empty() && st.top().X <= x) {
			if (st.top().X == x)
				cnt += st.top().Y;
			res += st.top().Y;
			st.pop();
		}

		if (!st.empty())
			res++; // x보다 큰 사람
		st.push({ x, cnt });
	}

	cout << res;
	return 0;
}