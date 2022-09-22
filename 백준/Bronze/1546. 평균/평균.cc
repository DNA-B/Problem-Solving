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
	int max = -1;
	int lecture = 0;
	double arr[1000] = { 0 };
	double mean = 0;

	cin >> lecture;
	
	for (int i = 0; i < lecture; i++)
	{
		cin >> arr[i];
		
		if (arr[i] > max)
		{
			max = arr[i];
		}
	}

	for (int i = 0; i < lecture; i++)
	{
		arr[i] = (arr[i] / max) * 100;
		mean += arr[i];
	}

	printf("%.2lf", mean / lecture);

	return 0;
}