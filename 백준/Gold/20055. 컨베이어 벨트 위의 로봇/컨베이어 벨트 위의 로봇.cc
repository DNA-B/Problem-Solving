#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#include<unordered_set>
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
int N, K, cnt = 0, res = 0;
deque<pair<int, bool>> dq;
//=========================//

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG

	cin >> N >> K;

	for (int x, i = 0; i < 2 * N; i++) {
		cin >> x;
		dq.push_back({ x, false });
	}

	while (cnt < K) {
		// 1. 벨트가 각 칸 위에 있는 로봇과 함께 한 칸 회전한다.
		dq.push_front(dq.back());
		dq.pop_back();
		dq[N - 1].Y = false; // 로봇 내리기

		// 2. 가장 먼저 벨트에 올라간 로봇부터, 벨트가 회전하는 방향으로 한 칸 이동할 수 있다면 이동한다.만약 이동할 수 없다면 가만히 있는다.
		for (int i = N - 1; i > 0; i--) {
			if (dq[i - 1].Y) { // 이전 칸에 로봇이 있을 때
				if (dq[i].X > 0 && !dq[i].Y) {// 현재 칸에 로봇이 없고 내구도가 0보다 크면 이동
					dq[i] = { dq[i].X - 1, true };
					dq[i - 1].Y = false;
					cnt += (dq[i].X == 0);
				}
			}
		}

		// 3. 올리는 위치에 있는 칸의 내구도가 0이 아니면 올리는 위치에 로봇을 올린다.
		if (dq[0].X > 0 && !dq[0].Y) {
			dq[0] = { dq[0].X - 1, true };
			cnt += (dq[0].X == 0);
		}

		dq[N - 1].Y = false; // 로봇 내리기
		res++;
	}

	cout << res;
}