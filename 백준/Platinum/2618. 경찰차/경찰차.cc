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
int N, W;
int mem[1005][1005];
pair<int, int> arr1[1005], arr2[1005];
//=========================//

int solve(int car1, int car2) {
	if (mem[car1][car2] != -1)
		return mem[car1][car2];
	if (car1 == W || car2 == W)
		return 0;

	int nxt = max(car1, car2) + 1;
	int dist1 = abs(arr1[car1].X - arr1[nxt].X) + abs(arr1[car1].Y - arr1[nxt].Y);
	int dist2 = abs(arr2[car2].X - arr2[nxt].X) + abs(arr2[car2].Y - arr2[nxt].Y);

	mem[car1][car2] = min(dist1 + solve(nxt, car2), dist2 + solve(car1, nxt));
	return mem[car1][car2];
}

void path(int car1, int car2) {
	if (car1 == W || car2 == W)
		return;

	int nxt = max(car1, car2) + 1;
	int dist1 = abs(arr1[car1].X - arr1[nxt].X) + abs(arr1[car1].Y - arr1[nxt].Y);
	int dist2 = abs(arr2[car2].X - arr2[nxt].X) + abs(arr2[car2].Y - arr2[nxt].Y);

	if (dist1 + solve(nxt, car2) < dist2 + solve(car1, nxt)) {
		cout << 1 << '\n';
		path(nxt, car2);
	}
	else {
		cout << 2 << '\n';
		path(car1, nxt);
	}
}

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
	// freopen("input.txt", "r", stdin);

	cin >> N >> W;

	for (int i = 0; i <= W; i++)
		fill(mem[i], mem[i] + (W + 1), -1);

	arr1[0] = { 1, 1 }, arr2[0] = { N, N };
	for (int i = 1; i <= W; i++) {
		cin >> arr1[i].X >> arr1[i].Y;
		arr2[i] = arr1[i];
	}

	cout << solve(0, 0) << '\n';
	path(0, 0);
	return 0;
}