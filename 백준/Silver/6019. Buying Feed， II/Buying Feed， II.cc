#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#include <unordered_set>
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
int N, K, E;
int res = 0;
pair<int, int> arr[105];
//=========================//

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG

	cin >> K >> E >> N;

	int x, f, c;
	for (int i = 0; i < N; i++) {
		cin >> x >> f >> c;
		arr[i] = { c + (E - x), f };
	}

	sort(arr, arr + N);

	for (int i = 0; i < N; i++) {
		int d = min(K, arr[i].Y);
		K -= d;
		res += d * arr[i].X;
	}

	cout << res;
}