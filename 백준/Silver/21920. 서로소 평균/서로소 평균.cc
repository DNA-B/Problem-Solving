#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>

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
int N, x;
int arr[500005];
//=========================//

int gcd(int a, int b) {
	return b ? gcd(b, a % b) : a;
}

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	cin >> x;

	ll res = 0, cnt = 0;
	for (int i = 0; i < N; i++) {
		if (gcd(arr[i], x) == 1) {
			res += arr[i];
			cnt++;
		}
	}

	cout << fixed << setprecision(6);
	cout << res / ((1.0) * cnt);
}