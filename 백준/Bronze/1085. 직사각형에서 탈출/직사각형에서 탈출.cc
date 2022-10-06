#include <iostream>
#include <cctype>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
	int x = 0;
	int y = 0;
	int w = 0;
	int h = 0;

	int xy = 0;
	int xwyh = 0;
	int min = 0;

	cin >> x >> y >> w >> h;

	xy = x < y ? x : y;
	xwyh = h - y < w - x ? h - y : w - x;

	min = xy < xwyh ? xy : xwyh;

	cout << min;
	return 0;
}