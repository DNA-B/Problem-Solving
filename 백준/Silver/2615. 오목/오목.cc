#include <bits/stdc++.h>

using namespace std;

#define ROW 19
#define COL 19
#define REP 8

int board[21][21];
int ans = INT_MAX, ans_x = INT_MAX, ans_y = INT_MAX;
int dx[] = { -1, 0, 1, -1, 1, -1, 0, 1 };
int dy[] = { -1, -1, -1, 0, 0, 1, 1, 1 };

bool check_five(int player, int dir, int x, int y) // 해당 라인 6개 이상 검사 함수
{
	vector<pair<int, int>> v = { {x, y} };
	int nx = x, ny = y;

	for (int i = 0; i < 5; i++) // 정방향
	{
		nx += dx[dir];
		ny += dy[dir];

		if (nx < 1 || nx > ROW || ny < 1 || ny > COL) // 범위 밖에 있거나, 플레이어랑 다르면 false
			continue;
		if (board[nx][ny] != player)
			continue;

		v.push_back({ nx, ny });
	}

	nx = x, ny = y;
	for (int i = 0; i < 5; i++) // 반대방향
	{
		nx -= dx[dir];
		ny -= dy[dir];

		if (nx < 1 || nx > ROW || ny < 1 || ny > COL) // 범위 밖에 있거나, 플레이어랑 다르면 false
			continue;
		if (board[nx][ny] != player)
			continue;

		v.push_back({ nx, ny });
	}

	return (v.size() == 5 ? true : false);
}

void solve(int player, int x, int y)
{
	for (int dir = 0; dir < REP; dir++)
	{
		int i;
		int cur_x = x, cur_y = y, nx = x, ny = y;
		bool omok = true;

		for (i = 0; i < 4; i++) // 나머지 4개 확인
		{
			nx += dx[dir];
			ny += dy[dir];

			if ((nx < 1 || nx > ROW || ny < 1 || ny > COL) || board[nx][ny] != player) // 범위 밖에 있거나, 플레이어랑 다르면 false
			{
				omok = false;
				break;
			}


			if (cur_y > ny)
			{
				cur_x = nx;
				cur_y = ny;
			}
			else if (cur_y == ny && cur_x > ny)
			{
				cur_x = nx;
				cur_y = ny;
			}
		}

		if (omok && check_five(player, dir, x, y))
		{
			ans_x = cur_x;
			ans_y = cur_y;
			ans = player;
			return;
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	for (int i = 1; i <= ROW; i++)
		for (int j = 1; j <= COL; j++)
			cin >> board[i][j];

	for (int i = 1; i <= ROW; i++)
	{
		for (int j = 1; j <= COL; j++)
		{
			if (board[i][j] != 0)
				solve(board[i][j], i, j);

			if (ans != INT_MAX)
			{
				cout << ans << "\n" << ans_x << " " << ans_y;
				return 0;
			}
		}
	}

	cout << 0;

	return 0;
}