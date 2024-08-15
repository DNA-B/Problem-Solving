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
int N, P, tmp;
vector<int> v;
/***********************/

int main() {
	cin.tie(NULL)->ios_base::sync_with_stdio(false);
	// freopen("input.txt", "r", stdin);

	cin >> N >> P;

	v.push_back(N);
	tmp = N;

	while (1) {
		tmp = (tmp * N) % P;
		auto it = find(v.begin(), v.end(), tmp);

		if (it != v.end()) {
			cout << v.size() - (it - v.begin());
			break;
		}
		else
			v.push_back(tmp);
	}

	return 0;
}