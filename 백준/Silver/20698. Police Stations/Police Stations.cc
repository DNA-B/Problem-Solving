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
int mnx = INT_MAX, mxx = INT_MIN, mny = INT_MAX, mxy = INT_MIN;
//=========================//

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG

	cin >> N;

	for (int xi, yi, i = 0; i < N; i++) {
		cin >> xi >> yi;
		mnx = min(mnx, xi), mxx = max(mxx, xi);
		mny = min(mny, yi), mxy = max(mxy, yi);
	}

	int L = ceil((mxx - mnx) / 2.0);
	int W = ceil((mxy - mny) / 2.0);
	cout << L << ' ' << W;
}