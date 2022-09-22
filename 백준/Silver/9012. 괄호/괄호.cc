#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	string str;
	int count = 0;
	int n;
	bool yes = true;

	cin >> n;

	while (n--)
	{
		stack<char> st;
		yes = true;

		cin >> str;

		for (int i = 0; i < str.size(); i++)
		{
			if (str[i] == '(') st.push(str[i]);
			else if (str[i] == ')')
			{
				if (!st.empty() && st.top() == '(')
				{
					st.pop();
				}
				else
				{
					yes = false;
					break;
				}
			}
		}

		if (!st.empty()) yes = false;

		if (yes)
		{
			cout << "YES\n";
		}
		else
		{
			cout << "NO\n";
		}
	}

	return 0;
}