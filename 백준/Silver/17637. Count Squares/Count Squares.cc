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
int H, V;
ll x[1505], y[1505];
unordered_map<int, int> diff;
//=========================//

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG

	cin >> H >> V;

	for (int i = 0; i < H; i++) cin >> y[i];
	for (int i = 0; i < V; i++) cin >> x[i];

	for (int i = 0; i < H; i++)
		for (int j = 0; j < i; j++)
			diff[y[i] - y[j]]++;

	long long res = 0;
	for (int i = 0; i < V; i++)
		for (int j = 0; j < i; j++)
			res += diff[x[i] - x[j]];

	cout << res;
}