#include <bits/stdc++.h>

using namespace std;

int arr[6];
int result = 0;

int main() 
{
	
	for (int i = 0; i < 5; i++)
	{
		cin >> arr[i];
		result += pow(arr[i], 2);
	}

	result %= 10;
	cout << result;
    
	return 0;

}