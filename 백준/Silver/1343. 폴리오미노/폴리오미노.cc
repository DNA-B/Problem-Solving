#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

using namespace std;

string s;

bool check(int idx, int mode) // 치환할 자리가 모두 X인지 검사
{
	if (mode == 1) // A
	{
		for (int i = idx; i < idx + 4; i++)
		{
			if (s[i] == '.' || s[i] == 'A' || s[i] == NULL)
				return false;
		}
	}
	else if (mode == 2) // B
	{
		for (int i = idx; i < idx + 2; i++)
		{
			if (s[i] == '.' || s[i] == 'A' || s[i] == 'B' || s[i] == NULL)
				return false;
		}
	}

	return true;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	// freopen("input.txt", "r", stdin);

	cin >> s;

	for (int i = 0; i <= (int)s.size() - 3; i++) // A 치환
	{
		if (s[i] == 'X' && check(i, 1))
		{
			s.replace(i, 4, "AAAA");
			i += 3;
		}
	}

	for (int i = 0; i <= (int)s.size() - 2; i++) // B 치환
	{
		if (s[i] == 'X' && check(i, 2))
		{
			s.replace(i, 2, "BB");
			i += 1;
		}
	}

	if (count(s.begin(), s.end(), 'X') > 0) // X가 남아있으면 -1
		cout << "-1";
	else
		cout << s;

	return 0;
}