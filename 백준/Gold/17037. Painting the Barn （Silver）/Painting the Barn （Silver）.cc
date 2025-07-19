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
int N, K;
int imos[1005][1005];
//=========================//

void proc_imos(int x, int y) {
	for (int i = x; i <= 1000; i++) {
		for (int j = y; j <= 1000; j++)
			imos[i][j] += imos[i - x][j - y];
	}
}

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG

	cin >> N >> K;

	int x1, y1, x2, y2;
	while (N--) {
		cin >> x1 >> y1 >> x2 >> y2;
		imos[x1][y1]++;
		imos[x2][y1]--;
		imos[x1][y2]--;
		imos[x2][y2]++;
	}

	proc_imos(1, 0);
	proc_imos(0, 1);

	int cnt = 0;
	for (int i = 0; i <= 1000; i++) {
		for (int j = 0; j <= 1000; j++)
			if (imos[i][j] == K) cnt++;
	}

	cout << cnt;
}