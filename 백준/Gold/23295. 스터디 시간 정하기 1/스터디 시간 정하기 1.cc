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
int N, K, T;
int imos[100005], psum[100005];
//=========================//

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG

	cin >> N >> T;

	for (int i = 0; i < N; i++) {
		cin >> K;

		int s, e;
		for (int j = 0; j < K; j++) {
			cin >> s >> e;
			imos[s]++;
			imos[e]--;
		}
	}

	for (int i = 1; i <= 100000; i++)
		imos[i] += imos[i - 1];

	ll cur = 0;
	for (int i = 0; i < T; i++)
		cur += imos[i];

	ll mx = cur;
	int se = 0, en = T;
	for (int i = T; i <= 100000; i++) {
		cur -= imos[i - T];
		cur += imos[i];

		if (cur > mx) {
			mx = cur;
			se = i - T + 1;
			en = i + 1;
		}
	}

	cout << se << ' ' << en;
}