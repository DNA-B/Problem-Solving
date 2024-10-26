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
int X, N, mx, l1, l2;
int arr[1000005];
//=========================//

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
	// freopen("input.txt", "r", stdin);

	while (cin >> X >> N) {
		mx = -1;
		X *= 10000000;

		for (int i = 0; i < N; i++)
			cin >> arr[i];

		sort(arr, arr + N);

		for (int i = 0; i < N - 1; i++) { // 내 뒤의 조각을 찾아야하므로 N - 1까지
			auto it = lower_bound(arr + (i + 1), arr + N, X - arr[i]); // 내 뒤의 조각을 찾아야하므로 범위는 [i + 1, N)

			if (*it + arr[i] == X) {
				if (*it - arr[i] > mx) {
					mx = *it - arr[i];
					l1 = arr[i];
					l2 = *it;
				}
			}
		}

		if (mx != -1)
			cout << "yes " << l1 << " " << l2 << '\n';
		else
			cout << "danger\n";
	}

	return 0;
}