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
int N, M, K, mx = -1;
int vis[25];
vector<int> v[25];
//=========================//

void solve(int idx, int cnt) {
	if (cnt == N) {
		int tmp = 0;
		for (int i = 0; i < M; i++) {
			bool flag = true;
			for (int skill : v[i]) {
				if (!vis[skill]) {
					flag = false;
					break;
				}
			}
			if (flag) tmp++;
		}
		mx = max(mx, tmp);
		return;
	}

	for (int i = idx; i <= 2 * N; i++) {
		vis[i] = 1;
		solve(i + 1, cnt + 1);
		vis[i] = 0;
	}
}

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG

	cin >> N >> M >> K;

	for (int i = 0; i < M; i++) {
		for (int x, j = 0; j < K; j++) {
			cin >> x;
			v[i].push_back(x);
		}
	}

	solve(1, 0);
	cout << mx;
}