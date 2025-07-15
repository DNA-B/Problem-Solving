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
vector<tuple<int, int, int, int>> order2;
ll arr[1005][1005], tmp[1005][1005];
//=========================//

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG

	cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++)
			cin >> arr[i][j];
	}

	int order, x1, y1, x2, y2, k;
	while (M--) {
		cin >> order >> x1 >> y1 >> x2 >> y2;
		x1++, y1++, x2++, y2++; // 1-base
		switch (order) {
			case 1:
				cin >> k;
				tmp[x1][y1] += k;
				tmp[x1][y2 + 1] -= k;
				tmp[x2 + 1][y1] -= k;
				tmp[x2 + 1][y2 + 1] += k;
				break;
			case 2:
				order2.push_back({ x1, y1, x2, y2 });
				break;
		}
	}

	for (int i = 1; i <= N; i++) { // row
		for (int j = 1; j <= N; j++)
			tmp[i][j] += tmp[i - 1][j];
	}

	for (int i = 1; i <= N; i++) { // col
		for (int j = 1; j <= N; j++)
			tmp[i][j] += tmp[i][j - 1];
	}

	for (int i = 1; i <= N; i++) { // arr + imos
		for (int j = 1; j <= N; j++)
			arr[i][j] += tmp[i][j];
	}

	for (int i = 1; i <= N; i++) { // prefix_sum
		for (int j = 1; j <= N; j++)
			arr[i][j] += arr[i - 1][j] + arr[i][j - 1] - arr[i - 1][j - 1];
	}

	for (auto [x1, y1, x2, y2] : order2)
		cout << arr[x2][y2] - arr[x2][y1 - 1] - arr[x1 - 1][y2] + arr[x1 - 1][y1 - 1] << '\n';
}