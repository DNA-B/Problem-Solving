#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	string str;
	int count = 0;

	while (1)
	{
		getline(cin, str);
		if (str == "#") return 0;

		for (int i = 0; i < str.length(); i++)
		{
			if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u')
			{
				count++;
			}

			if (str[i] == 'A' || str[i] == 'E' || str[i] == 'I' || str[i] == 'O' || str[i] == 'U')
			{
				count++;
			}
		}

		cout << count << "\n";
		count = 0;
	}

	return 0;
}