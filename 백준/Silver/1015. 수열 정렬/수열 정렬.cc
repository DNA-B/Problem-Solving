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
int N;
int res[55];
vector<pair<int, int>> v;
//=========================//

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG

	cin >> N;

	for (int x, i = 0; i < N; i++) {
		cin >> x;
		v.push_back({ x, i });
	}

	sort(v.begin(), v.end());

	for (int i = 0; i < N; i++)
		res[v[i].Y] = i;

	for (int i = 0; i < N; i++)
		cout << res[i] << ' ';
}