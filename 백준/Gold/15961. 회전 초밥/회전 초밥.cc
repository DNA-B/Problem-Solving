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
int N, d, k, c, cnt = 0, res = 0;
int arr[3005000], vis[3005];
queue<int> q;
//=========================//

void check() {
	if (vis[c]) // 쿠폰 초밥이 이미 존재하면
		res = max(res, cnt); // 추가 X
	else
		res = max(res, cnt + 1); // 추가 O
}

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG

	cin >> N >> d >> k >> c; // 접시, 초밥, 연속, 쿠폰

	for (int i = 0; i < N; i++)
		cin >> arr[i];
	for (int i = N; i < N + k; i++)
		arr[i] = arr[i - N]; // 원형

	for (int i = 0; i < k; i++) {
		vis[arr[i]]++;
		if (vis[arr[i]] == 1) cnt++;
	}

	check();

	for (int i = k; i < N + k; i++) {
		vis[arr[i - k]]--;
		if (vis[arr[i - k]] == 0) cnt--;
		vis[arr[i]]++;
		if (vis[arr[i]] == 1) cnt++;
		check();
	}

	cout << res;
}