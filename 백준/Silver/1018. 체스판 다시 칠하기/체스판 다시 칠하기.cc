#define _CRT_SECURE_NO_WARNINGS

#include <iostream> // C++ library
#include <algorithm>
#include <string>
#include <cctype> // C library
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <vector> // STL
#include <queue>
#include <stack>
#include <list>

using namespace std;

// 흑, 백 비교 체스판 설정
vector<string> black = { {"BWBWBWBW"},{"WBWBWBWB"},{"BWBWBWBW"},{"WBWBWBWB"},
								 {"BWBWBWBW"},{"WBWBWBWB"},{"BWBWBWBW"},{"WBWBWBWB"} };
vector<string> white = { {"WBWBWBWB"},{"BWBWBWBW"},{"WBWBWBWB"},{"BWBWBWBW"},
								 {"WBWBWBWB"},{"BWBWBWBW"},{"WBWBWBWB"},{"BWBWBWBW"} };


bool in_board(int x, int m) // x부터 8칸 검사 가능한지 여부
{
	if (x + 7 < m)
		return true;
	else
		return false;
}

// 흑, 백 체스판과 비교하며 칠해본 뒤 둘 중 더 적은 수 채택
void re_paint(vector<string> v, int x, int y, int n, int m, int min)
{
	int b_count = 0;
	int w_count = 0;
	int xi = 0, yi = 0;
	if (y + 7 == n)
	{
		cout << min;
		return;
	}

	if (in_board(x, m) == true)
	{

			for (int i = y; i < y + 8; i++)
			{
				for (int j = x; j < x + 8; j++)
				{
					if (white[yi][xi] != v[i][j])
						w_count++;
					if (black[yi][xi] != v[i][j])
						b_count++;
					xi++;
				}
				xi = 0;
				yi++;
			}

			if (min > (b_count < w_count ? b_count : w_count))
				min = b_count < w_count ? b_count : w_count;

			return re_paint(v, x + 1, y, n, m, min); // x 증가시키며 오른쪽으로 이동
	}
	else if(in_board(x, m) == false)
	{
		x = 0;
		re_paint(v, x, y + 1, n, m, min); // x부터 8칸 검사가 안 될 경우 y증가
	}
}

int main()
{
	vector<string> chess;
	string temp;
	int n, m;
	int x = 0, y = 0;
	int min = 10000;

	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		cin >> temp;
		chess.push_back(temp);
	}

	re_paint(chess, x, y, n, m, min);
	return 0;
}