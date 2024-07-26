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
ll attack[100001];
/***********************/

int main() {
	cin.tie(NULL)->ios_base::sync_with_stdio(false);
	// freopen("input.txt", "r", stdin);

	cin >> N >> jw;

	for (int i = 0; i < N - 1; i++)
		cin >> attack[i];

	sort(attack, attack + (N - 1));

	for (int i = 0; i < N - 1; i++) {
		if (jw <= attack[i]) {
			cout << "No";
			exit(0);
		}
		if (jw > attack[i])
			jw += attack[i];
	}

	cout << "Yes";
	return 0;
}