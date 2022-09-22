#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	string stick;
	stack<char> st;
	char prev;
	int cnt = 0;

	cin >> stick;

	for (int i = 0; i < stick.size(); i++)
	{
		if (stick[i] == '(') st.push(stick[i]);
		
		if (stick[i] == ')')
		{
			if (!st.empty() && prev == ')')
			{
				st.pop();
				cnt++;
			}
			else if (!st.empty() && st.top() == '(')
			{
				st.pop();
				cnt += st.size();
			}
		}
		prev = stick[i];
	}
	cout << cnt;

	return 0;
}