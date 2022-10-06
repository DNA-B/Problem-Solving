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

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	string grade;

	cin >> grade;

	if (grade == "A+")
	{
		cout << "4.3";
	}
	else if (grade == "A0")
	{
		cout << "4.0";
	}
	else if (grade == "A-")
	{
		cout << "3.7";
	}
	else if (grade == "B+")
	{
		cout << "3.3";
	}
	else if (grade == "B0")
	{
		cout << "3.0";
	}
	else if (grade == "B-")
	{
		cout << "2.7";
	}
	else if (grade == "C+")
	{
		cout << "2.3";
	}
	else if (grade == "C0")
	{
		cout << "2.0";
	}
	else if (grade == "C-")
	{
		cout << "1.7";
	}
	else if (grade == "D+")
	{
		cout << "1.3";
	}
	else if (grade == "D0")
	{
		cout << "1.0";
	}
	else if (grade == "D-")
	{
		cout << "0.7";
	}
	else
	{
		cout << "0.0";
	}
	return 0;
}