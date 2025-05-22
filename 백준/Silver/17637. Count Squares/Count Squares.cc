#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#include <unordered_map>
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
int H, V, cnt = 0;
int x[1005], y[1005];
unordered_map<ll, ll> diff_x, diff_y;
//=========================//

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG

	cin >> H >> V;

	for (int i = 0; i < H; ++i) cin >> y[i];
	for (int i = 0; i < V; ++i) cin >> x[i];

	for (int i = 0; i < H; ++i) {
		for (int j = i + 1; j < H; ++j)
			diff_y[y[j] - y[i]]++;
	}

	for (int i = 0; i < V; ++i) {
		for (int j = i + 1; j < V; ++j)
			diff_x[x[j] - x[i]]++;
	}

	for (auto& [diff, count_y] : diff_y) {
		if (diff_x.count(diff))
			cnt += count_y * diff_x[diff];
	}

	cout << cnt << '\n';
}