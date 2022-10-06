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
	int arr[9];
	
	int max = -1;
	int index = -1;

	for (int i = 0; i < 9; i++)
	{
		cin >> arr[i];
		
		if (arr[i] > max)
		{
			max = arr[i];
			index = i;
		}
	}

	cout << max << endl << index + 1;
	return 0;
}