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
int N, M, H;
int arr[100005], imos[100005];
//=========================//

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG

	cin >> N >> M;

	for (int i = 1; i <= N; i++)
		cin >> arr[i];

	int a, b, k;
	while (M--) {
		cin >> a >> b >> k;
		imos[a] += k;
		imos[b + 1] -= k;
	}

	for (int i = 1; i <= N; i++)
		imos[i] += imos[i - 1];

	for (int i = 1; i <= N; i++)
		cout << arr[i] + imos[i] << ' ';
}