#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>

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
int N;
ll mem[505][505];
vector<pair<int, int>> v;
//=========================//

ll solve(int i, int j) {
	if (i == j)
		return 0;
	if (mem[i][j] != -1)
		return mem[i][j];

	ll res = LL_INF;
	for (int k = i; k < j; k++) {
		ll cur = solve(i, k) + solve(k + 1, j) + (1LL * v[i].X * v[k].Y * v[j].Y);
		res = min(res, cur);
	}

	return mem[i][j] = res;
}

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG

	cin >> N;

	int r, c;
	for (int i = 0; i < N; i++) {
		cin >> r >> c;
		v.push_back({ r, c });
	}

	memset(mem, -1, sizeof(mem));
	solve(0, N - 1);
	cout << mem[0][N - 1];
}