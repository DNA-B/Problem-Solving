#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

//========= MACRO =========//
#define PI 3.1415926535897932
#define INF 0x3f3f3f3f
#define LL_INF 1e18
#define ll long long
#define X first
#define Y second
//=========================//

//======= VARIABLEs =======//
int cnt = 0;
int N, K, A, B;
int arr[205];
//=========================//

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG

	cin >> N >> K >> A >> B;

	fill(arr, arr + N, K);

	while (!count(arr, arr + N, 0)) {
		int idx = min_element(arr, arr + N) - arr;

		for (int i = 0; i < N; i++) {
			arr[i]--;
			if (idx <= i && i < idx + A)
				arr[i] += B;
		}

		cnt++;
	}

	cout << cnt;
}