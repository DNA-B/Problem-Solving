#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

using namespace std;

string order;
int problem = 0;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	// freopen("input.txt", "r", stdin);

	getline(cin, order);

	while (order != "고무오리 디버깅 끝")
	{
		getline(cin, order);

		if (order == "문제")
			problem++;

		if (order == "고무오리")
		{
			if (problem == 0) // 풀 문제가 없는데 고무오리면 두 문제 추가
				problem += 2;
			else
				problem--;
		}
	}

	if (problem)
		cout << "힝구";
	else
		cout << "고무오리야 사랑해";

	return 0;
}