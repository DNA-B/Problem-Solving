#include <iostream>
#include <cctype>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int main() 
{
	int alp[26] = { 0 };
	string str;

	cin >> str;

	fill_n(alp, 26, -1);

	for (int i = 0; i < str.size(); i++)
	{
		if (alp[str[i] - 97] == -1)
		{
			alp[str[i] - 97] = i;
		}
		else
		{
			continue;
		}
		
	}

	for (int index : alp)
	{
		cout << index << ' ';
	}
	return 0;
}