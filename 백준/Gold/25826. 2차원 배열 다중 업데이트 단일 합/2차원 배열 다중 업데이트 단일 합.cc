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
ll arr[1005][1005], tmp[1005][1005];
//=========================//

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
			cin >> arr[i][j];
	}

	int order, x1, y1, x2, y2, k;
	for (int i = 0; i < M - 1; i++) {
		cin >> order >> x1 >> y1 >> x2 >> y2 >> k;
		tmp[x1][y1] += k;
		tmp[x1][y2 + 1] -= k;
		tmp[x2 + 1][y1] -= k;
		tmp[x2 + 1][y2 + 1] += k;
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N - 1; j++)
			tmp[i][j + 1] += tmp[i][j];
	}

	for (int i = 0; i < N - 1; i++) {
		for (int j = 0; j < N; j++)
			tmp[i + 1][j] += tmp[i][j];
	}

	cin >> order >> x1 >> y1 >> x2 >> y2;

	ll res = 0;
	for (int i = x1; i <= x2; i++) {
		for (int j = y1; j <= y2; j++)
			res += arr[i][j] + tmp[i][j];
	}

	cout << res;
}