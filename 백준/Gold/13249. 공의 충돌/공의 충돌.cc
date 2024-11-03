#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;
//========= MACRO =========//
#define PI 3.1415926535897932
#define INT_INF 0x3f3f3f3f
#define LL_INF 1e18
#define ll long long
#define X first
#define Y second
//=========================//

//======= VARIABLEs =======//
int N, T, r;
int arr[15];
//=========================//

bool check(int i, int j) {
	bool f1 = arr[i] <= (arr[j] + (T * 2));
	bool f2 = arr[i] >= (arr[j] - (T * 2));
	return f1 && f2;
}

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
	// freopen("input.txt", "r", stdin);

	cin >> N;

	for (int i = 0; i < N; i++)
		cin >> arr[i];

	cin >> T;

	for (int i = 0; i < N; i++) {
		for (int j = i - 1; j >= 0; j--)
			r += check(i, j);
	}

	cout << r / 4.0;
	return 0;
}