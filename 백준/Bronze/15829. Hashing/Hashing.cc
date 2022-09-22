#include <iostream>
#include <cctype>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>

using namespace std;


// 15829번 : Hashing

long long math_pow(int index)
{
	long long r = 1;

	for (int i = 0; i < index; i++)
	{
		r = ( r * 31 ) % 1234567891;
	}
	return r;
}

int main() 
{
	char arr[51] = { '\0' };
	int arr_len = 0;
	long long result = 0;

	cin >> arr_len;

	for (int i = 0; i < arr_len; i++)
	{
		cin >> arr[i]; 
		result += ((arr[i] - 96) * math_pow(i)) % 1234567891;
	}

	cout << result % 1234567891;

	return 0;

}
