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
	int n; 
	int a = 0;
	int b = 0;

	cin >> n;

	for(int i = 0;i<n;i++)
	{
		cin >> a;
		cin >> b;

		cout << a + b;
		cout << '\n';
	}

	return 0;
}