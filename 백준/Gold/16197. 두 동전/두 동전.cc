#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

using namespace std;

int N, M;
char board[21][21];
int vis[21][21][21][21];
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };
pair<int, int> coin1, coin2;
queue<tuple<int, int, int, int, int>> q; // {coin1, coin2, cnt}

bool is_out(int x, int y) // 떨어졌는지 확인하는 함수
{
	return (x < 0 || x >= N || y < 0 || y >= M);
}

int bfs()
{
	int x1, y1, x2, y2, cnt;

	while (!q.empty())
	{
		tie(x1, y1, x2, y2, cnt) = q.front();
		q.pop();

		if (cnt > 10)
			return -1;

		for (int dir = 0; dir < 4; dir++)
		{
			int nx1 = x1 + dx[dir];
			int nx2 = x2 + dx[dir];
			int ny1 = y1 + dy[dir];
			int ny2 = y2 + dy[dir];

			if (is_out(nx1, ny1) && is_out(nx2, ny2)) // 둘 다 나감
				continue;

			if (is_out(nx1, ny1) || is_out(nx2, ny2)) // 하나만 나감
				return (cnt + 1 > 10 ? -1 : cnt + 1);

			if (board[nx1][ny1] == '#' && board[nx2][ny2] == '#') // 둘 다 벽 만남
				continue;

			if (board[nx1][ny1] == '#') // 하나만 벽을 만났다면 하나는 움직이고 다른 하나는 가만히 있어야한다.
			{
				nx1 = x1;
				ny1 = y1;
			}
			else if (board[nx2][ny2] == '#')
			{
				nx2 = x2;
				ny2 = y2;
			}

			if (vis[nx1][ny1][nx2][ny2])
				continue;

			q.push({ nx1, ny1, nx2, ny2, cnt + 1 });
			vis[nx1][ny1][nx2][ny2] = 1;
		}
	}

	return -1;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	// freopen("input.txt", "r", stdin);

	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> board[i][j];

			if (board[i][j] == 'o')
			{
				if (coin1.first == NULL && coin1.second == NULL)
					coin1 = { i, j };
				else
					coin2 = { i, j };
			}
		}
	}

	q.push({ coin1.first, coin1.second, coin2.first, coin2.second, 0 });
	vis[coin1.first][coin1.second][coin2.first][coin2.second] = 1;

	cout << bfs();

	return 0;
}