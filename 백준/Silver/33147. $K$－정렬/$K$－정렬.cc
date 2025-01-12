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
int N, K, gcd_NK;
int arr[1000005];
//=========================//

int gcd(int a, int b) {
	return b == 0 ? a : gcd(b, a % b);
}

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG

	cin >> N >> K;
	gcd_NK = gcd(N, K);

	for (int x, i = 0; i < N; i++) {
		cin >> x;
		if ((x % gcd_NK) != (i % gcd_NK)) {
			cout << "NO";
			exit(0);
		}
	}

	cout << "YES";
}