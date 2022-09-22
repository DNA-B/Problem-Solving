#include <bits/stdc++.h>

using namespace std;

int main() // 괄호 쌍 문제와 비슷한 풀이
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	string str;
	int count = 0;
	int n;
	
	cin >> n;

	while (n--)
	{
		stack<char> st;

		cin >> str;

		for (int i = 0; i < str.size(); i++)
		{
			if (str[i] == 'A')
			{
				if (st.empty())
				{
					st.push(str[i]);
				}
				else if (st.top() == 'A')
				{
					st.pop();
				}
				else
				{
					st.push(str[i]);
				}
			}

			if (str[i] == 'B')
			{
				if (st.empty())
				{
					st.push(str[i]);
				}
				else if (st.top() == 'B')
				{
					st.pop();
				}
				else
				{
					st.push(str[i]);
				}
			}
		}

		if (st.empty())
		{
			count++;
		}
	}

	cout << count;

	return 0;
}