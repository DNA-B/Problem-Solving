#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

using namespace std;

/******** MACRO ********/
#define BOUND 51
#define INF 0x3f3f3f3f
#define LLINF 1e18
#define MOD 1'000'000'007
#define PI 3.1415926535897932
#define ll long long
#define X first
#define Y second
/***********************/

/****** VARIABLEs ******/
int year;
/***********************/

int main() {
	cin.tie(NULL)->ios_base::sync_with_stdio(false);
	// freopen("input.txt", "r", stdin);

	cin >> year;
	// cout << 2013 % 12 << " " << 2013 % 10 << "\n";  --> 9 3이므로 12지는 8칸 더해서 모듈러, 10간은 6칸 더해서 모듈러
	cout << (char)(((year + 8) % 12) + 65) << (year + 6) % 10;

	return 0;
}