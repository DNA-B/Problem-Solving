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
int N, cnt = 0;
int arr[2005];
//=========================//

bool check(int i, int j, int lo, int hi) {
	for (int k = lo; k < hi; k++) {
		if (k != i && k != j && k != N) {
			if (arr[k] == arr[i] - arr[j])
				return true;
		}
	}

	return false;
}

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG


	cin >> N;

	for (int i = 0; i < N; i++)
		cin >> arr[i];

	sort(arr, arr + N);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (i == j) continue;

			// 만약 같은 수가 3개 이상일 경우(ex: 0 0 0) lower_bound만 사용하면 빠지는 경우가 발생한다.
			int lo = lower_bound(arr, arr + N, arr[i] - arr[j]) - arr;
			int hi = upper_bound(arr, arr + N, arr[i] - arr[j]) - arr; // x = y + z --> x - y = z

			if (check(i, j, lo, hi)) {
				cnt++;
				break;
			}
		}
	}

	cout << cnt;
}