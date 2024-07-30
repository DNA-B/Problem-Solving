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
int D, N, r;
int d[300005] = { INT_MAX };
stack<int> st;
/***********************/

int main() {
	cin.tie(NULL)->ios_base::sync_with_stdio(false);
	// freopen("input.txt", "r", stdin);

	cin >> D >> N;

	for (int i = 1; i <= D; i++) {
		cin >> d[i];
		d[i] = min(d[i], d[i - 1]);
	}

	cin >> r; // 1번째 피자

	for (int i = 1; i <= D; i++) {
		if (r > d[i])
			break;
		st.push(d[i]);
	}

	for (int i = 2; i <= N; i++) { // 1번 피자 들어간 앞부터 탐색
		cin >> r;

		while (!st.empty()) { // 들어갈 수 있으면 바로 들어감
			st.pop();
			if (st.empty() || r <= st.top())
				break;
		}
	}

	cout << st.size();
	return 0;
}