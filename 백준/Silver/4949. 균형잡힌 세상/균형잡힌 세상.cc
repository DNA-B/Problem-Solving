#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	string str;
	bool no = false;

	while (1)
	{
		stack<char> st;
		no = false;

		getline(cin, str);
		if (str == ".") break;

		for (int i = 0; i < str.size(); i++)
		{
			if (str[i] == '(' || str[i] == '[') // 여는 괄호는 모두 push
			{
				st.push(str[i]);
			}

			if (str[i] == ')')
			{
				if (st.size() == 0 || st.top() != '(') // size가 0이면 여는 괄호가 없다.
				{
					no = true;
					break;
				}
				st.pop();
			}

			if (str[i] == ']')
			{
				if (st.size() == 0 || st.top() != '[')
				{
					no = true;
					break;
				}
				st.pop();
			}
		}

		if (!st.empty()) no = true; // 반복문이 끝나고 스택이 비어있지 않으면 짝이 맞지 않은 것

		if (!no)
		{
			cout << "yes\n";
		}
		else
		{
			cout << "no\n";
		}
	}
	return 0;
}