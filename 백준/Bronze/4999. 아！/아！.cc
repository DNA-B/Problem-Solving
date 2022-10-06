#include <iostream>
#include <algorithm> 
#include <string> 
// #include <numeric>
// #include <cctype> 
// #include <cmath>
// #include <stack> 
// #include <queue>
// #include <deque>
// #include <list>
// #include <set>
#include <vector>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	string jh;
	string doctor;
		
	cin >> jh >> doctor;

	if (jh.size() < doctor.size())
	{
		cout << "no";
	}
	else
	{
		cout << "go";
	}

	return 0;
}
