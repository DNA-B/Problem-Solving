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
int N, M;
ll mx_cost = -1, mx_total = -1;
int arr[1005];
//=========================//

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG

	cin >> N >> M;

	for (int i = 0; i < M; i++)
		cin >> arr[i];

	sort(arr, arr + M);

	for (int i = 0; i < M; i++) {
		ll total = 0;
		int cost = arr[i];
		int cnt = 0;
		for (int j = M - 1; j >= 0; j--) {
			if (arr[j] >= cost) {
				total += cost;
				cnt++;
			}

			if (cnt == N)
				break;
		}

		if (total > mx_total) {
			mx_total = total;
			mx_cost = cost;
		}
	}

	cout << mx_cost << ' ' << mx_total;
}