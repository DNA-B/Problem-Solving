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
int N, H;
int imos[500005];
//=========================//

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG

	cin >> N >> H;

	for (int x, i = 0; i < N; i++) {
		cin >> x;
		if (i % 2 == 0) { // 석순
			imos[0]++;
			imos[x]--;
		}
		else { // 종유석
			imos[H - x]++;
			imos[H]--;
		}
	}

	for (int i = 1; i < H; i++)
		imos[i] += imos[i - 1];

	int mn = *min_element(imos, imos + H);
	cout << mn << " " << count(imos, imos + H, mn);

}