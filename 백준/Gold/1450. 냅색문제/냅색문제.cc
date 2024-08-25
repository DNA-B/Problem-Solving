#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;

/******** MACRO ********/
#define PI 3.1415926535897932
#define MOD 1000000007
#define INT_INF 0x3f3f3f3f
#define LL_INF 1e18
#define ll long long
#define ull usnsigned long long
#define X first
#define Y second
/***********************/

/****** VARIABLEs ******/
int N, C;
int arr[45];
ll cnt = 0;
vector<ll> v; // multiset으로 선언하고 distance쓰면 시간 초과 -> distance의 시간복잡도가 O(N)임
/***********************/

void l_dfs(int cur, ll total) {
	if (total > C)
		return;
	if (cur == N / 2) {
		v.push_back(total);
		return;
	}

	l_dfs(cur + 1, total + arr[cur]);
	l_dfs(cur + 1, total);
}

void r_dfs(int cur, ll total) {
	if (total > C)
		return;
	if (cur == N) {
		cnt += upper_bound(v.begin(), v.end(), C - total) - v.begin();
		return;
	}

	r_dfs(cur + 1, total + arr[cur]);
	r_dfs(cur + 1, total);
}

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
	// freopen("input.txt", "r", stdin);

	cin >> N >> C;

	for (int i = 0; i < N; i++)
		cin >> arr[i];

	l_dfs(0, 0);
	sort(v.begin(), v.end());
	r_dfs(N / 2, 0);

	cout << cnt;
	return 0;
}