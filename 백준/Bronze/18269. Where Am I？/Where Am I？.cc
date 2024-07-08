#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

using namespace std;

/******** MACRO ********/
#define BOUND 50001
#define INF 0x3f3f3f3f
#define MOD 1'000'000'007
#define PI 3.1415926535897932
#define ll long long
#define X first
#define Y second
/***********************/

/****** VARIABLEs ******/
int N;
string s;
/***********************/

int main() {
	cin.tie(NULL)->ios_base::sync_with_stdio(false);
	// freopen("input.txt", "r", stdin);

	cin >> N >> s;

	for (int k = 1; k <= N; k++) {
		bool flag = true;

		for (int i = 0; i <= N - k; i++) {
			string tmp = s.substr(i, k);

			for (int j = 0; j <= N - k; j++) {
				if (i == j)
					continue;
				if (tmp == s.substr(j, k))
					flag = false;
			}
		}

		if (flag) {
			cout << k;
			break;
		}
	}

	return 0;
}