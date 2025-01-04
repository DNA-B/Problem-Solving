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
int N, res = -1, total = 0;
int arr[100005];
//=========================//

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
	// freopen("input.txt", "r", stdin);

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
		arr[i + N] = arr[i];
		total += arr[i];
	}

	int hi = 1, cur = arr[0];
	for (int lo = 0; lo < N; lo++) {
		while (hi < 2 * N && cur <= total / 2) {
			cur += arr[hi];
			hi++;
		}

		cur -= arr[--hi];
		if (cur > res) res = cur;
		cur -= arr[lo];
	}

	cout << res;
}