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
int N, P, R, C;
int arr[1005][1005];
bool chk[1005][1005];
pair<ll, int> mem[1005][1005];
//=========================//

bool operator>=(const pair<ll, int>& a, const pair<ll, int>& b) {
	if (a.X == b.X)
		return a.Y > b.Y;
	return a.X > b.X;
}

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG

	cin >> N;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++)
			cin >> arr[i][j];
	}

	cin >> P;

	while (P--) {
		cin >> R >> C;
		chk[R][C] = true;
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (mem[i - 1][j] >= mem[i][j - 1]) {
				mem[i][j].X = mem[i - 1][j].X + arr[i][j];
				mem[i][j].Y = mem[i - 1][j].Y + chk[i][j];
			}
			else {
				mem[i][j].X = mem[i][j - 1].X + arr[i][j];
				mem[i][j].Y = mem[i][j - 1].Y + chk[i][j];
			}
		}
	}

	cout << mem[N][N].X << ' ' << mem[N][N].Y;
}