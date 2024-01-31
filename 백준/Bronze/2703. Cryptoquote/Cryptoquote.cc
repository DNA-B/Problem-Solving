#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

using namespace std;

int T, N, Q;
char ch;
char translate[26];
string message;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	// freopen("input.txt", "r", stdin);

	cin >> T;

	while (T--)
	{
		cin.ignore();
		getline(cin, message);

		for (int i = 0; i < 26; i++)
		{
			cin >> ch;
			translate[i] = ch;
		}

		for (int i = 0; i < message.size(); i++)
		{
			if (message[i] == ' ')
				continue;
			else
				message[i] = translate[message[i] - 'A'];
		}

		cout << message << "\n";
	}


	return 0;
}