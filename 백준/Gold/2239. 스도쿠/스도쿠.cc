#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

using namespace std;

string board[82];
int cnt = 0;
vector<pair<int, int>> v;

bool check(pair<int, int> xy)
{
	int x = xy.first, y = xy.second;
	int loc_x, loc_y, bound_x1, bound_x2, bound_y1, bound_y2;

	loc_x = x / 3;
	loc_y = y / 3;
	bound_x1 = 3 * loc_x; // 정사각형 세로 시작점
	bound_x2 = 3 * (loc_x + 1); // 정사각형 세로 끝점
	bound_y1 = 3 * loc_y; // 정사각형 가로 시작점
	bound_y2 = 3 * (loc_y + 1); // 정사각형 가로 끝점

	for (int i = 0; i < 9; i++)
	{
		if (board[x][i] == board[x][y] && i != y) // 가로에 같은 숫자
			return false;
	}

	for (int i = bound_x1; i < bound_x2; i++)
	{
		for (int j = bound_y1; j < bound_y2; j++)
		{
			if (board[i][j] == board[x][y] && (i != x && j != y)) // 정사각형에 같은 숫자
				return false;
		}
	}

	for (int i = 0; i < 9; i++)
	{
		if (board[i][y] == board[x][y] && i != x) // 세로에 같은 숫자
			return false;
	}

	return true;
}

void solve(int n)
{
	if (n == cnt)
	{
		for (int i = 0; i < 9; i++)
			cout << board[i] << "\n";

		exit(0);
	}

	int nx = v[n].first;
	int ny = v[n].second;

	for (int i = 1; i <= 9; i++)
	{
		board[nx][ny] = i + '0';

		if (check({ nx, ny }))
			solve(n + 1);
	}

	board[nx][ny] = 0 + '0'; // 해가 없으면 다시 0으로
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	// freopen("input.txt", "r", stdin);

	for (int i = 0; i < 9; i++)
	{
		cin >> board[i];

		for (int j = 0; j < 9; j++)
		{
			if (board[i][j] == '0')
			{
				v.push_back({ i, j });
				cnt++;
			}
		}
	}

	solve(0);

	return 0;
}