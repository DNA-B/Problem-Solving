#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

using namespace std;

string s, tmp, max_word;
int cnt;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	// freopen("input.txt", "r", stdin);

	while (cin >> s)
	{
		tmp = "";
		cnt = 0;

		if (s == "E-N-D")
			break;

		for (char item : s)
		{
			if (('a' <= item && item <= 'z') || ('A' <= item && item <= 'Z') || item == '-') // cin이 공백 단위 입력이라 공백은 검사 안해도 됨.
			{
				tmp += item;
				cnt++;
			}
			else
			{
				if (max_word.size() < cnt)
					max_word = tmp;

				tmp = "";
				cnt = 0;
			}
		}

		if (max_word.size() < cnt)
			max_word = tmp;
	}

	transform(max_word.begin(), max_word.end(), max_word.begin(), ::tolower);

	cout << max_word;

	return 0;
}