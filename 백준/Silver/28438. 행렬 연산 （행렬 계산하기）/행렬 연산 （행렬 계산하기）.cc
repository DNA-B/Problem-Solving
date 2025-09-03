#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

//========= MACRO =========//
#define PI 3.1415926535897932
#define INF 0x3f3f3f3f
#define LL_INF 1e18
#define ll long long
//#define X first
//#define Y second
//=========================//

//======= VARIABLEs =======//
int N, M, Q;
int row[500005], col[500005];
//=========================//

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG

	cin >> N >> M >> Q;

	int order, rc, v;
	while (Q--) {
		cin >> order >> rc >> v;

		if (order == 1)
			row[rc] += v;
		else
			col[rc] += v;
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++)
			cout << row[i] + col[j] << ' ';
		cout << '\n';
	}
}