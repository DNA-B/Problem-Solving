#include <iostream>
#include <algorithm> 
// #include <string> 
// #include <cctype> 
// #include <cmath> 
// #include <queue>
// #include<deque>
// #include <set>
 #include <vector>
// #include <stack> 
// #include <bitset>

using namespace std;

int y(int time)
{
	if (time < 30)
	{
		return 10;
	}
	else
	{
		return 10 + (10 * (time / 30));
	}
}

int m(int time)
{
	if (time < 60)
	{
		return 15;
	}
	else
	{
		return 15 + (15 * (time / 60));
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int num;
	int time;
	int yungsik = 0;
	int minsik = 0;

	cin >> num;
	for (int i = 0; i < num; i++)
	{
		cin >> time;
		yungsik += y(time);
		minsik += m(time);
	}

	if (yungsik == minsik)
	{
		cout << "Y M " << yungsik;
		return 0;
	}
	else
	{
		yungsik < minsik ? cout << "Y " << yungsik : cout << "M " << minsik;
	}
	
	return 0;
}