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
int N, W, P;
int d[105][105];
//=========================//

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG

	cin >> N >> W >> P;

	for (int i = 1; i <= N; i++) // init
		fill(d[i], d[i] + 1 + N, INF);

	while (W--) {
		int a, b, c;
		cin >> a >> b >> c;
		d[a][b] = min(d[a][b], c);
		d[b][a] = min(d[b][a], c);
	}

	for (int i = 1; i <= N; i++)
		d[i][i] = 0;

	for (int k = 1; k <= N; k++) {
		for (int st = 1; st <= N; st++) {
			for (int en = 1; en <= N; en++) {
				if (d[st][en] > d[st][k] + d[k][en])
					d[st][en] = d[st][k] + d[k][en];
			}
		}
	}

	int st, en;
	while (P--) {
		cin >> st >> en;
		cout << d[st][en] << '\n';
	}
}