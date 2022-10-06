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

	cin >> n;

	for (int i = n; i > 0; i--)
	{
		for (int j = 0; j <= n - i; j++)
		{
			cout << '*';
		}
		cout << '\n';
	}
	
	
	return 0;

}