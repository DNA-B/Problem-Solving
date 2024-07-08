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

	for (int i = 0; i < N; i++) {
		set<string> sub_s;
		bool flag = true;

		for (int j = 0; j < N - i; j++) {
			if (sub_s.insert(s.substr(j, i + 1)).Y == false) { // insert할 때, 이미 있는 값이면 pair second 값이 false.
				flag = false;
				break;
			}
		}

		if (flag) {
			cout << i + 1;
			break;
		}
	}

	return 0;
}