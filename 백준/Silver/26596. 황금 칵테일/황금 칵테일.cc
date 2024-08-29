#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

/******** MACRO ********/
#define PI 3.1415926535897932
#define MOD 1000000007
#define INT_INF 0x3f3f3f3f
#define LL_INF 1e18
#define ll long long
#define X first
#define Y second
/***********************/

/****** VARIABLEs ******/
int N;
unordered_map<string, int> m;
/***********************/

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
	// freopen("input.txt", "r", stdin);

	cin >> N;

	string name;
	int q;
	while (N--) {
		cin >> name >> q;
		m[name] += q;
	}

	for (auto item1 : m) {
		for (auto item2 : m) {
			if (item1.X == item2.X)
				continue;
			int q1 = item1.Y * 1.618;
			if (q1 == item2.Y) {
				cout << "Delicious!";
				exit(0);
			}
		}
	}

	cout << "Not Delicious...";
	return 0;
}