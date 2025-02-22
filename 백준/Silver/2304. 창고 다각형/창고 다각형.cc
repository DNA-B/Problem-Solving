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
int N, L, H, res = 0;
int arr[1005];
//=========================//

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG

	cin >> N;

	int mx_h = -1, mx_pos = -1;
	for (int i = 0; i < N; i++) {
		cin >> L >> H;
		arr[L] = H;
		if (mx_h < H) {
			mx_h = H;
			mx_pos = L;
		}
	}

	int cur_mx = 0; // Left
	for (int i = 1; i < mx_pos; i++) {
		cur_mx = max(cur_mx, arr[i]);
		res += cur_mx;
	}

	cur_mx = 0; // Right
	for (int i = 1000; i > mx_pos; i--) {
		cur_mx = max(cur_mx, arr[i]);
		res += cur_mx;
	}

	cout << res + mx_h;
}