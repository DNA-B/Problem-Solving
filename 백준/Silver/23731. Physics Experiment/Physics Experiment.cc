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
bool is_round = false;
string N;
ll nxt, mx = -1;
/***********************/


int main() {
	cin.tie(NULL)->ios_base::sync_with_stdio(false);
	// freopen("input.txt", "r", stdin);

	cin >> N;

	for (int i = N.size() - 1; i >= 0; i--) {
		nxt = (N[i] - '0') + is_round;
		N[i] = (nxt == 10 ? N[i] : nxt + '0');
		mx = max(mx, stoll(N));
		is_round = (N[i] - '0') >= 5;
		N[i] = '0';
	}

	if (is_round) {
		N[0] = '0';
		N.insert(0, "1");
	}

	mx = max(mx, stoll(N));
	cout << mx;

	return 0;
}