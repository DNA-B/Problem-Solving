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
int N;
string reply;
vector<int> lo, hi;
/***********************/

bool check(int ans) {
	for (int n : lo) {
		if (n >= ans)
			return false;
	}
	for (int n : hi) {
		if (n <= ans)
			return false;
	}

	return true;
}

int main() {
	cin.tie(NULL)->ios_base::sync_with_stdio(false);
	// freopen("input.txt", "r", stdin);

	while (1) {
		cin >> N;

		if (N == 0)
			break;

		cin.ignore();
		getline(cin, reply);

		if (reply == "right on") {
			cout << (check(N) ? "Stan may be honest\n" : "Stan is dishonest\n");
			lo.clear(), hi.clear();
			continue;
		}

		if (reply == "too high")
			hi.push_back(N);
		else if (reply == "too low")
			lo.push_back(N);

	}

	return 0;
}