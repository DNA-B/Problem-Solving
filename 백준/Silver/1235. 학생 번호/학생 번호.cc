#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

using namespace std;

/******** MACRO ********/
#define BOUND 100001
#define INF 0x3f3f3f3f
#define MOD 1'000'000'007
#define PI 3.1415926535897932
#define ll long long
#define X first
#define Y second
/***********************/

/****** VARIABLEs ******/
int N;
vector<string> v;
/***********************/

int main() {
	cin.tie(NULL)->ios_base::sync_with_stdio(false);
	// freopen("input.txt", "r", stdin);

	cin >> N;
	v.resize(N);

	for (auto& number : v)
		cin >> number;

	for (int i = 1; i <= v[0].size(); i++) {
		set<string> s;

		for (int j = 0; j < v.size(); j++)
			s.insert(v[j].substr(v[j].size() - i));

		if (s.size() == N) {
			cout << i;
			exit(0);
		}
	}

	return 0;
}