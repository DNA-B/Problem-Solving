#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

using namespace std;

int A;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	// freopen("input.txt", "r", stdin);

	cin >> A;

	for (int i = 1; i <= A; i++)
	{
		if (31 % (i + 1) == 1) // 상대가 부를 수 있는 수가 31 딱 하나만 남게 만들면 된다
			cout << i << "\n";
	}

	return 0;
}