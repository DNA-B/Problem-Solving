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
int N, K, mx = -1;
int arr[200005], vis[100005];
//=========================//

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG

	cin >> N >> K;

	for (int i = 0; i < N; i++)
		cin >> arr[i];

	for (int en = 0, st = 0; st < N; st++) {
		while (en < N && vis[arr[en]] < K) {
			vis[arr[en]]++;
			en++;
		}
		mx = max(mx, en - st);
		if (en == N) break;
		vis[arr[st]]--;
	}

	cout << mx;
}