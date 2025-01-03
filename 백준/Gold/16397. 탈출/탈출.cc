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
const int BOUND = 99999;
int N, T, G;
int vis[100005];
queue<int> q;
//=========================//

int change_num(int x) {
	if (x == 0)
		return 0;

	string tmp = to_string(x);
	tmp[0] = ((tmp[0] - '0') - 1) + '0';

	if (tmp[0] == '0')
		tmp.erase(0, 1);

	return stoi(tmp);
}

void to_next(int cur, int nxt) {
	if (vis[nxt] == -1) {
		vis[nxt] = vis[cur] + 1;
		q.push({ nxt });
	}
}

bool bfs() {
	while (!q.empty()) {
		int cur = q.front(); q.pop();

		if (vis[cur] + 1 > T) continue;
		if (cur + 1 <= BOUND) to_next(cur, cur + 1);
		if (2 * cur <= BOUND) to_next(cur, change_num(2 * cur));
	}

	return vis[G] != -1;
}

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
	// freopen("input.txt", "r", stdin);

	cin >> N >> T >> G;

	fill(vis, vis + (BOUND + 1), -1);
	vis[N] = 0;
	q.push(N);

	if (bfs()) cout << vis[G];
	else cout << "ANG";
}