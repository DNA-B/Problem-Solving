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
	int arr[10] = { 0 };
	
	int a;
	int b;
	int c;

	int sum = 0;
	string str;

	cin >> a;
	cin >> b;
	cin >> c;

	sum = a * b * c;
	str = to_string(sum);

	for (int i = 0; i < str.size(); i++)
	{
		arr[str[i] - '0']++;
	}

	for (int i = 0; i < 10; i++)
	{
		cout << arr[i] << endl;
	}
	return 0;
}
