#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
//#include <algorithm> 
//#include <string> 
// #include <cctype> 
//#include <cmath> 
//#include <queue>
// #include<deque>
// #include <set>
// #include <vector>
// #include <stack> 
// #include <bitset>

using namespace std;

int main()
{
	int y1, y2, y3, y4;
	int yoot = 0;
	int rep = 3;
	
	
	while (rep > 0)
	{
		cin >> y1 >> y2 >> y3 >> y4;
		yoot = y1 + y2 + y3 + y4;

		switch (yoot)
		{
		case 0:
			cout << "D\n";
			break;
		case 1:
			cout << "C\n";
			break;
		case 2:
			cout << "B\n";
			break;
		case 3:
			cout << "A\n";
			break;
		case 4:
			cout << "E\n";
			break;
		}
		rep--;
	}
	
	return 0;
}