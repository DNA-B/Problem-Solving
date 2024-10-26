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
int X, N;
int arr[1000005];
//=========================//

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
	// freopen("input.txt", "r", stdin);

	while (cin >> X >> N) {
		X *= 10000000;

		for (int i = 0; i < N; i++)
			cin >> arr[i];

		sort(arr, arr + N);

		int lo = 0, hi = N - 1;

		while (lo < hi) {
			if (arr[lo] + arr[hi] == X) {
				cout << "yes " << arr[lo] << " " << arr[hi] << "\n";
				break;
			}
			(arr[lo] + arr[hi] < X) ? lo++ : hi--;
		}
        
		if (lo >= hi)
			cout << "danger\n";
	}
	return 0;
}