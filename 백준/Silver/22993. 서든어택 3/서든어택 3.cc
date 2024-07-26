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
bool flag = true;
ll jw;
vector<ll> attack;
/***********************/

int main() {
	cin.tie(NULL)->ios_base::sync_with_stdio(false);
	// freopen("input.txt", "r", stdin);

	cin >> N >> jw;
	attack.resize(N - 1);

	for (auto& a : attack)
		cin >> a;

	sort(attack.begin(), attack.end());

	for (auto a : attack) {
		if (jw > a)
			jw += a;
		else
			flag = false;
	}

	cout << (flag ? "Yes" : "No");
	return 0;
}