#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#include <unordered_set>
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
int N, mx = -1;
bool is_broken[10];
pair<int, int> arr[10];
//=========================//

void solve(int cur, int cnt) {
	// 가장 최근에 든 계란이 가장 오른쪽에 위치한 계란일 경우 계란을 치는 과정을 종료한다.
	if (cur == N) {
		mx = max(mx, cnt);
		return;
	}

	// 손에 든 계란이 깨졌거나 깨지지 않은 다른 계란이 없으면 현재 계란을 치지 않고 넘어간다.
	if (is_broken[cur] || cnt >= N - 1) {
		solve(cur + 1, cnt);
		return;
	}

	auto [s1, w1] = arr[cur];
	for (int i = 0; i < N; i++) {
		if (i != cur && !is_broken[i]) {
			auto [s2, w2] = arr[i];

			arr[cur].X = s1 - w2;
			is_broken[cur] = (arr[cur].X <= 0);
			arr[i].X = s2 - w1;
			is_broken[i] = (arr[i].X <= 0);

			solve(cur + 1, cnt + is_broken[cur] + is_broken[i]);

			arr[cur].X = s1;
			is_broken[cur] = false;
			arr[i].X = s2;
			is_broken[i] = false;
		}
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
		cin >> arr[i].X >> arr[i].Y;

	solve(0, 0);
	cout << mx;
}