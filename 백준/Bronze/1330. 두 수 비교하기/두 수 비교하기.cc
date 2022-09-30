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
	int a = 0;
	int b = 0;

	cin >> a;
	cin >> b;

	if (a > b)
	{
		cout << '>';
	}
	else if (a < b)
	{
		cout << '<';
	}
	else
	{
		cout << "==";
	}
	
	return 0;

}