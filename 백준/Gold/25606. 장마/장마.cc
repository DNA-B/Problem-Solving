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
int N, M, Q;
int psum[100005], imos[200005];
//=========================//

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG

	cin >> N >> M >> Q;

	for (int x, i = 1; i <= N; i++) {
	    cin >> x;
		psum[i] += psum[i - 1] + x;
        
        int st = i + 1;
        int en = st + (x / M);
		imos[st] += M;
		imos[en] -= M - (x % M); // 마지막 날은 잔여 빗물
		imos[en + 1] -= x % M;
	}

	for (int i = 1; i <= N; i++)
		imos[i] += imos[i - 1];

	for (int i = 1; i <= N; i++)
		imos[i] += imos[i - 1];

	int order, idx;
	while (Q--) {
		cin >> order >> idx;

		if (order == 1)
			cout << psum[idx] - imos[idx] << '\n';
		else
			cout << imos[idx] - imos[idx - 1] << '\n';
	}
}