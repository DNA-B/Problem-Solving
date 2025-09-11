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
int N, M;
int products[1005];
//=========================//

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG

	cin >> N >> M;

	for (int k, i = 1; i <= N; i++) {
		cin >> k;
		for (int p, j = 0; j < k; j++) {
			cin >> p;
			products[p] = i;
		}
	}

	if (count(products + 1, products + (M + 1), 0) > 0) {
		cout << "NO";
		exit(0);
	}

	cout << "YES" << '\n';

	for (int i = 1; i <= N; i++)
		cout << i << ' ';
	cout << '\n';
	for (int i = 1; i <= M; i++)
		cout << products[i] << ' ';
}