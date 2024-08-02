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
int mem[30];
/***********************/

int main() {
	cin.tie(NULL)->ios_base::sync_with_stdio(false);
	// freopen("input.txt", "r", stdin);

	cin >> N;

	mem[1] = 1, mem[4] = -1;
	for (int i = 2; i <= N; i++) {
		if (i & 1) mem[i + 3] -= mem[i - 1];
		else mem[i + 4] -= mem[i - 1];
		mem[i] += mem[i - 1] * 2;
	}

	cout << mem[N];
	return 0;
}