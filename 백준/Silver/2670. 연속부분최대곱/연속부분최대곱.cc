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
int N;
double mx = -1.0;
double arr[10005];
//=========================//

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
		mx = max(mx, arr[i]);
	}

	for (int i = 0; i < N - 1; i++) {
		double cur = arr[i];
		for (int j = i + 1; j < N; j++) {
			cur *= arr[j];
			mx = max(mx, cur);
		}
	}

	cout << fixed << setprecision(3) << mx;
}