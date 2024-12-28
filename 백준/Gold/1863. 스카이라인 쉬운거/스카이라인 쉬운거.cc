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
int N, res = 0;
stack<int> st;
//=========================//

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
	// freopen("input.txt", "r", stdin);

	cin >> N;

	int x, y;
	while (N--) {
		cin >> x >> y;

		while (!st.empty() && st.top() > y) {
			st.pop();
			res++;
		}

		if (st.empty() || st.top() < y)
			st.push(y);
	}

	while (!st.empty()) {
		res += (st.top() != 0);
		st.pop();
	}

	cout << res;
}