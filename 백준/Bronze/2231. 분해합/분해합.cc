#include <iostream>
#include <cctype>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <string>

using namespace std;

// 2231번 : 분석합

int main()
{
	string str; // 문자열 접근  >> 시간 복잡도 낮추기
	string temp;
	int sum = 0;
	int target;

	cin >> str;

	target = stoi(str);
	
	for (int i = 1; i < target; i++)
	{
		temp = to_string(i);
		sum += i;

		for (int i = 0; i < temp.size(); i++)
		{
			sum += temp[i] - '0';
		}

		if (sum == target)
		{
			cout << i;
			return 0;
		}

		sum = 0;
	}

	cout << 0;

	return 0;
}