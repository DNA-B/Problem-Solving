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
	int num = 0;
	int repeat = 0;
	string str;

	cin >> num;

	for (int i = 0; i < num; i++)
	{
		cin >> repeat;
		cin >> str;

		for (int j = 0; j < str.size(); j++)
		{
			for (int k = 0; k < repeat; k++)
			{
				cout << str[j];
			}
		}
		cout << endl;
	}
	return 0;
}