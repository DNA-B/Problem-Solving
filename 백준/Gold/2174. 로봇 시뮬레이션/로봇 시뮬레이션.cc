#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

using namespace std;

int A, B, N, M;
int board[101][101];
vector<tuple<int, int, char>> robot(101); // {x, y, dir}

void change_dir(int n_robot, char order)
{
	if (order == 'L')
	{
		if (get<2>(robot[n_robot]) == 'N')
			get<2>(robot[n_robot]) = 'W';
		else if (get<2>(robot[n_robot]) == 'W')
			get<2>(robot[n_robot]) = 'S';
		else if (get<2>(robot[n_robot]) == 'S')
			get<2>(robot[n_robot]) = 'E';
		else if (get<2>(robot[n_robot]) == 'E')
			get<2>(robot[n_robot]) = 'N';
	}
	else if (order == 'R')
	{
		if (get<2>(robot[n_robot]) == 'N')
			get<2>(robot[n_robot]) = 'E';
		else if (get<2>(robot[n_robot]) == 'W')
			get<2>(robot[n_robot]) = 'N';
		else if (get<2>(robot[n_robot]) == 'S')
			get<2>(robot[n_robot]) = 'W';
		else if (get<2>(robot[n_robot]) == 'E')
			get<2>(robot[n_robot]) = 'S';
	}
}

bool go_forward(int n_robot)
{
	char robot_dir = get<2>(robot[n_robot]);
	int cur_y = get<0>(robot[n_robot]);
	int cur_x = get<1>(robot[n_robot]);

	if (robot_dir == 'N')
	{
		board[cur_y][cur_x] = 0;
		cur_y++;
	}
	else if (robot_dir == 'W')
	{
		board[cur_y][cur_x] = 0;
		cur_x--;
	}
	else if (robot_dir == 'S')
	{
		board[cur_y][cur_x] = 0;
		cur_y--;
	}
	else if (robot_dir == 'E')
	{
		board[cur_y][cur_x] = 0;
		cur_x++;
	}

	if (cur_y < 1 || cur_y > B || cur_x < 1 || cur_x > A)
	{
		cout << "Robot " << n_robot << " crashes into the wall";
		return false;
	}
	else if (board[cur_y][cur_x] != 0)
	{
		cout << "Robot " << n_robot << " crashes into robot " << board[cur_y][cur_x];
		return false;
	}

	board[cur_y][cur_x] = n_robot;
	get<0>(robot[n_robot]) = cur_y;
	get<1>(robot[n_robot]) = cur_x;

	return true;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	// freopen("input.txt", "r", stdin);

	cin >> A >> B >> N >> M;

	int x, y;
	char dir;
	for (int i = 1; i <= N; i++)
	{
		cin >> x >> y >> dir;

		board[y][x] = i;
		robot[i] = { y, x, dir };
	}

	int n_robot, rep;
	char order;
	for (int i = 0; i < M; i++)
	{
		bool is_possible = true;
		cin >> n_robot >> order >> rep;

		while (rep--)
		{
			switch (order)
			{
			case 'L':
				change_dir(n_robot, 'L');
				break;
			case 'R':
				change_dir(n_robot, 'R');
				break;
			case 'F':
				is_possible = go_forward(n_robot);
				break;
			}

			if (!is_possible)
				exit(0);
		}
	}

	cout << "OK";

	return 0;
}