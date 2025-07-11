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
int N, M, res = 0;
int parks[105], cars[2005], vis[2005];
queue<int> q_car;
priority_queue<int, vector<int>, greater<int>> pq_park;
//=========================//

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		cin >> parks[i];
		pq_park.push(i);
	}

	for (int i = 1; i <= M; i++)
		cin >> cars[i];

	for (int x, i = 0; i < 2 * M; i++) {
		cin >> x;

		if (x > 0 && pq_park.empty()) {
			q_car.push(x);
			continue;
		} // 이 밑으로 주차 자리가 없는 경우는 없음

		if (x < 0) {
			pq_park.push(vis[-x]);
			vis[-x] = 0;
			if (!q_car.empty()) { // 대기하던 차가 있다면 바로 주차
				x = q_car.front(); q_car.pop();
				int cur_park = pq_park.top(); pq_park.pop();
				vis[x] = cur_park;
				res += parks[cur_park] * cars[x];
			}
		}
		else if (x > 0) {
			if (!q_car.empty()) {// 대기하던 차가 있다면 먼저 주차
				q_car.push(x);
				x = q_car.front(); q_car.pop();
			}
			int cur_park = pq_park.top(); pq_park.pop();
			vis[x] = cur_park;
			res += parks[cur_park] * cars[x];
		}
	}

	cout << res;
}