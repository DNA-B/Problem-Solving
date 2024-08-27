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
bool lo, hi;
int N;
ll K;
ll arr[100005];
/***********************/

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
	// freopen("input.txt", "r", stdin);

	cin >> N;

	for (int i = 1; i <= N; i++)
		cin >> arr[i];

	cin >> K;

	for (int i = 1; i <= N; i++) {
		if (arr[i] == K * i)
			lo = hi = true;
		else if (arr[i] > K * i)
			hi = true;
		else
			lo = true;
	}

	cout << (lo && hi ? 'T' : 'F');
	return 0;
}