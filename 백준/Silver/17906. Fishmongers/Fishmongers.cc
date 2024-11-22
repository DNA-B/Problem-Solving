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
ll res = 0;
priority_queue<int> fish;
vector<pair<int, int>> v;
//=========================//

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
	// freopen("input.txt", "r", stdin);

	cin >> N >> M;

	for (int x, i = 0; i < N; i++) {
		cin >> x;
		fish.push(x);
	}

	for (int x, y, i = 0; i < M; i++) {
		cin >> x >> y;
		v.push_back({ y, x }); // { pay per kg , want }
	}

	sort(v.begin(), v.end(), greater<>());

	for (auto [pay, want] : v) {
		while (!fish.empty() && want > 0) {
			ll cur = fish.top();
			fish.pop();
			res += cur * pay;
			want--;
		}

		if (fish.empty())
			break;
	}

	cout << res;
}