#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

/******** MACRO ********/
#define INT_INF 0x3f3f3f3f
#define LL_INF 1e18
#define MOD 1'000'000'007
#define PI 3.1415926535897932
#define ll long long
#define X first
#define Y second
/***********************/

/****** VARIABLEs ******/
int N, Q, cur = 0;
int arr[200005];
/***********************/

int main() {
	cin.tie(NULL)->ios_base::sync_with_stdio(false);
	// freopen("input.txt", "r", stdin);

	cin >> N >> Q;

	for (int i = 0; i < N; i++)
		cin >> arr[i];

	while (Q--) {
		int order, i, x, s;
		cin >> order;

		switch (order) {
			case 1:
				cin >> i >> x;
				arr[((i - 1) + cur) % N] += x;
				break;
			case 2:
				cin >> s;
				cur = (cur - s) % N;
				if (cur < 0) cur += N;
				break;
			case 3:
				cin >> s;
				cur = (cur + s) % N;
				break;
		}
	}

	for (int i = 0; i < N; i++)
		cout << arr[(cur + i) % N] << " ";

	return 0;
}