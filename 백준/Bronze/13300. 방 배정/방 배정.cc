#include <iostream>
#include <algorithm> 
// #include <string> 
// #include <cctype> 
// #include <cmath> 
// #include <queue>
// #include<deque>
// #include <set>
 #include <vector>
// #include <stack> 
// #include <bitset>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int element_school[7][2] = { {0} };
	int n_student, k;
	int grade, sex;
	int room = 0;

	cin >> n_student >> k;

	for (int i = 0; i < n_student; i++)
	{
		cin >> sex >> grade;
		element_school[grade][sex]++;
	}

	for (int i = 1; i < 7; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			room += element_school[i][j] / k;

			if ((element_school[i][j] % k) != 0)
			{
				room++;
			}
		}
	}

	cout << room;

	return 0;
}