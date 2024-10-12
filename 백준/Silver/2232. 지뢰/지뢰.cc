#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

using namespace std;

/******** MACRO ********/
#define PI 3.1415926535897932
#define MOD 1000000007
#define INT_INF 0x3f3f3f3f
#define LL_INF 1e18
#define ll long long
#define X first
#define Y second
/***********************/

/****** VARIABLEs ******/
int N;
int arr[50005];
vector<bool> vis(50005);
vector<int> res;
priority_queue<pair<int, int>> pq;
/***********************/

void boom(int idx) {
	if (idx < 1 || idx > N)
		return;
	if (vis[idx])
		return;

	vis[idx] = 1;

	if (arr[idx] > arr[idx - 1])
		boom(idx - 1);
	if (arr[idx] > arr[idx + 1])
		boom(idx + 1);
}

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
	// freopen("input.txt", "r", stdin);

	cin >> N;

	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
		pq.push({ arr[i], i });
	}

	while (!pq.empty()) {
		auto [p, idx] = pq.top();
		pq.pop();

		if (!vis[idx]) {
			res.push_back(idx);
			boom(idx);
		}
	}

	sort(res.begin(), res.end());
	for (int x : res) cout << x << '\n';

	return 0;
}