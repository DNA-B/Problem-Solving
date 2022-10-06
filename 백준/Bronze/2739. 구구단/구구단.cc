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
	int n = 0;

	cin >> n;;
	

	for (int i = 1; i <= 9; i++)
	{
		cout << n << " * " << i << " = " << n * i;
		cout << '\n';
	}
	return 0;

}
