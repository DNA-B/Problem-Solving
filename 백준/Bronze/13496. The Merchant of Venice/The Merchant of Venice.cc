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
int K, N, S, D;
//=========================//

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG

	cin >> K;

	for (int tc = 1; tc <= K; tc++) {
		int d, v, total = 0;

		cin >> N >> S >> D;

		for (int i = 0; i < N; i++) {
			cin >> d >> v;
			if (S * D >= d) total += v;
		}

		cout << "Data Set " << tc << ":\n" << total << "\n\n";
	}
}