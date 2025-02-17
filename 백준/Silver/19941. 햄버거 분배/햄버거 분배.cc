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
string S;
int N, K, res = 0;
int vis[20005];
//=========================//

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG

	cin >> N >> K >> S;

	for (int i = 0; i < N; i++) {
		if (S[i] != 'P')
			continue;

		for (int j = i - K; j <= i + K; j++) {
			if ((0 <= j && j < N) && (!vis[j] && S[j] == 'H')) {
				vis[j] = 1;
				res++;
				break;
			}
		}
	}

	cout << res;
}