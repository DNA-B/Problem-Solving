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
int N, K, L;
int ham[200005], imos[400005];
//=========================//

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG

	cin >> N >> K >> L;

	for (int x, i = 1; i <= N; i++)
		cin >> ham[i];

	for (int x, i = 0; i < K; i++) {
		cin >> x;
		imos[x]++; imos[x + L]--;
	}

	for (int i = 1; i <= N; i++)
		imos[i] += imos[i - 1];

	sort(ham + 1, ham + N + 1, greater<int>());
	sort(imos + 1, imos + N + 1, greater<int>());

	ll m = 0;
	for (int i = 1; i <= N; i++) {
		if (imos[i] >= 30) continue;
		m += ham[i] / (1LL << imos[i]);
	}

	cout << m;
}