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
int N, Ax, Ay, Bx, By;
int board[405][405];
ll d[405][405];
int dx[] = { 0, 0, -1, 1 };
int dy[] = { 1, -1, 0, 0 };
priority_queue < tuple<ll, int, int>,
	vector<tuple<ll, int, int>>,
	greater<tuple<ll, int, int>>> pq;
//=========================//

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG

	cin >> N >> Ay >> Ax >> By >> Bx;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++)
			cin >> board[i][j];
	}

	if (board[Ax][Ay] == -1 || board[Bx][By] == -1) {
		cout << -1;
		exit(0);
	}

	fill(&d[0][0], &d[404][405], LL_INF);
	d[Ax][Ay] = board[Ax][Ay];
	pq.push({ d[Ax][Ay],Ax, Ay });

	while (!pq.empty()) {
		auto [cost, x, y] = pq.top();
		pq.pop();

		if (d[x][y] != cost)
			continue;

		for (int dir = 0; dir < 4; dir++) {
			int nx = x + dx[dir];
			int ny = y + dy[dir];

			if (nx < 1 || nx > N || ny < 1 || ny > N)
				continue;
			if (board[nx][ny] == -1)
				continue;
			if (d[nx][ny] <= cost + board[nx][ny])
				continue;

			d[nx][ny] = cost + board[nx][ny];
			pq.push({ d[nx][ny], nx, ny });
		}
	}

	cout << (d[Bx][By] == LL_INF ? -1 : d[Bx][By]);
}