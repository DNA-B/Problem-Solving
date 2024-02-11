#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

using namespace std;

int N, M, st, en;
string s;
int arr[26]; // 각 자리수의 합
bool res = false;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	// freopen("input.txt", "r", stdin);

	cin >> N;
	cin.ignore();
	fill(arr, arr + 26, -1);

	for (int i = 0; i < N; i++)
	{
		getline(cin, s);
		st = s[0] - 'a';
		en = s[s.size() - 1] - 'a';
		arr[st] = en;
	}

	cin >> M;
	cin.ignore();

	for (int i = 0; i < M; i++)
	{
		getline(cin, s);
		st = s[0] - 'a';
		en = s[s.size() - 1] - 'a';

		while (true)
		{
			if (arr[st] == en)
			{
				res = true;
				break;
			}
			else if (arr[st] == -1)
			{
				res = false;
				break;
			}

			st = arr[st];
		}

		if (res)
			cout << "T\n";
		else
			cout << "F\n";

		res = false;
	}

	return 0;
}