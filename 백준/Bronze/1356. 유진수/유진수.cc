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
string N;
/***********************/

int main() {
	cin.tie(NULL)->ios_base::sync_with_stdio(false);
	// freopen("input.txt", "r", stdin);

	cin >> N;

	for (int i = 0; i < N.size() - 1; i++) {
		int front = 1, back = 1;

		for (int j = 0; j <= i; j++)
			front *= N[j] - '0';
		for (int j = i + 1; j < N.size(); j++)
			back *= N[j] - '0';

		if (front == back) {
			cout << "YES";
			exit(0);
		}
	}

	cout << "NO";
	return 0;
}