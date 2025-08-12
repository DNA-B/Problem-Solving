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
int N, K, X, res;
int A[85], B[85];
bool mem[85][85][85 * 205];
//=========================//

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG

	cin >> N >> K >> X;

	for (int i = 1; i <= N; i++)
		cin >> A[i] >> B[i];


	mem[0][0][0] = true;

	int maxA = K * X;
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j <= min(i, K); j++) {
			for (int total = 0; total <= maxA; total++) {
				if (!mem[i - 1][j][total])
					continue;

				mem[i][j][total] = true;
				if (total + A[i] <= maxA)
					mem[i][j + 1][total + A[i]] = true;
			}
		}
	}

	int res = -1;
	for (int total = 0; total <= maxA; total++) {
		if (mem[N][K][total]) {
			int val = total * ((K * X) - total);
			res = max(res, val);
		}
	}

	cout << res;
}