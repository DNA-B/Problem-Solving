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
int N, d, k, c, mx = -1;
int arr[60005], vis[3005];
//=========================//

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG

	cin >> N >> d >> k >> c;

	for (int i = 0; i < N; i++)
		cin >> arr[i];

	for (int i = N; i < N + k; i++)
		arr[i] = arr[i - N];

	int cnt = 0;
	for (int i = 0; i < k; i++) {
		if (!vis[arr[i]]) cnt++;
		vis[arr[i]]++;
	}

	for (int i = k; i < N + k; i++) {
		if (vis[arr[i - k]]) {
			vis[arr[i - k]]--;
			if (!vis[arr[i - k]] && cnt > 0) cnt--;
		}

		if (!vis[arr[i]]) cnt++;
		vis[arr[i]]++;
		mx = max(mx, vis[c] ? cnt : cnt + 1);
	}

	cout << mx;
}