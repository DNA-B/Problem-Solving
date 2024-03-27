#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

using namespace std;

int N;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	// freopen("input.txt", "r", stdin);

	cin >> N;

	for (int i = N; i > 0; i--)
	{
		string tmp = to_string(i);
		bool is_gold_num = true;

		for (int j = 0; j < tmp.size(); j++)
		{
			if (!(tmp[j] == '4' || tmp[j] == '7'))
			{
				is_gold_num = false;
				break;
			}
		}

		if (is_gold_num)
		{
			cout << tmp;
			break;
		}

	}

	return 0;
}