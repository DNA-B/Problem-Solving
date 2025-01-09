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
int N, M, k, p;
ll arr[1005];
//=========================//

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG

	cin >> N;
	for (int t, i = 0; i < N; i++) {
		cin >> k;
		while (k--) {
			cin >> t;
			arr[i] |= (1LL << t);
		}
	}

	cin >> M;
	for (int p, q, i = 0; i < M; i++) {
		ll tmp = 0;
		cin >> p;
		while (p--) {
			cin >> q;
			tmp |= (1LL << q);
		}

		int res = 0;
		for (int j = 0; j < N; j++)
			res += ((tmp & arr[j]) == arr[j]);
		cout << res << '\n';
	}
}