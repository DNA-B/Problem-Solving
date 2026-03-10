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
int N;
int arr[25];
unordered_map<ll, bool> um;
//=========================//

void solve(int idx, ll total, int cnt) {
	if (cnt == N)
		return;

	for (int i = idx; i < N; i++) {
		um[total + arr[i]] = true;
		solve(i + 1, total + arr[i], cnt + 1);
	}
}

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG

	cin >> N;

	for (int i = 0; i < N; i++)
		cin >> arr[i];

	solve(0, 0, 0);

	ll total = accumulate(arr, arr + N, 0LL);

	if (total > um.size())
		cout << total - um.size();
	else
		cout << 0;
}