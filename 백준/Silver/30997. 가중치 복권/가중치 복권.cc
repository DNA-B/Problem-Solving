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
int N, M, K, T;
int counts[105];
tuple<int, int, int> res;
double mx = -1.0;
//=========================//

ll gcd(int a, int b) {
	return (b == 0 ? a : gcd(b, a % b));
}

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG

	cin >> N >> M >> K;

	T = 3 * M;
	ll dem = pow(T, K + 1);

	int a, b, c;
	for (int i = 0; i < M - 1; i++) {
		cin >> a >> b >> c;
		counts[a]++, counts[b]++, counts[c]++;
	}

	for (int i = 1; i <= N - 2; i++) {
		for (int j = i + 1; j <= N - 1; j++) {
			for (int k = j + 1; k <= N; k++) {
				int S = counts[i] + counts[j] + counts[k] + 3;
				ll num = S * pow(T - S, K);

				if (num / (1.0 * dem) > mx) {
					mx = num / (1.0 * dem);
					res = { i, j, k };
				}
			}
		}
	}

	auto [res_i, res_j, res_k] = res;
	int res_S = counts[res_i] + counts[res_j] + counts[res_k] + 3;
	ll res_num = res_S * pow(T - res_S, K);
	ll g = gcd(res_num, dem);

	cout << res_num / g << ' ' << dem / g << '\n';
	cout << res_i << ' ' << res_j << ' ' << res_k;
}