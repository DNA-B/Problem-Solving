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
int N, K;
int mem[105][100001];
pair<int, int> arr[105][2];
//=========================//

int solve(int idx, int t) {
	if (t > K) return INT_MIN;
	if (idx == N) return 0;
	if (mem[idx][t] != -1) return mem[idx][t];

	mem[idx][t] = max(
		solve(idx + 1, t + arr[idx][0].X) + arr[idx][0].Y,
		solve(idx + 1, t + arr[idx][1].X) + arr[idx][1].Y
	);

	return mem[idx][t];
}

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
	// freopen("input.txt", "r", stdin);

	cin >> N >> K;
	memset(mem, -1, sizeof(mem));
	for (int i = 0; i < N; i++)
		cin >> arr[i][0].X >> arr[i][0].Y >> arr[i][1].X >> arr[i][1].Y;
	cout << solve(0, 0);
}