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
int arr[200005], suffix_mx[200005], prefix_mn[200005];
//=========================//

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG

	cin >> N >> M;

	for (int i = 0; i < N; i++)
		cin >> arr[i];

	prefix_mn[0] = arr[0];
	for (int i = 1; i < N; i++)
		prefix_mn[i] = min(prefix_mn[i - 1], arr[i]);

	suffix_mx[N - 1] = arr[N - 1];
	for (int i = N - 2; i >= 0; i--)
		suffix_mx[i] = max(suffix_mx[i + 1], arr[i]);

	int mx = INT_MIN;
	for (int i = 0; i <= M; i++)
		mx = max(mx, suffix_mx[(N - 1) - (M - i)] - prefix_mn[i]);

	cout << mx;
}