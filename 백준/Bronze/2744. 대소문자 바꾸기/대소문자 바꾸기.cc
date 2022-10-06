#include <iostream>
#include <algorithm> 
// #include <string> 
#include <cctype> 
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
	
	string str;

	cin >> str;
	
	for (int i = 0; i < str.size(); i++)
	{
		if (islower(str[i]))
		{
			str[i] = toupper(str[i]);
		}
		else
		{
			str[i] = tolower(str[i]);
		}
	}

	cout << str;

	return 0;
}