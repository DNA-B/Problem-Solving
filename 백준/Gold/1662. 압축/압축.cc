#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

using namespace std;

string ziped_s;
int len = 0, tmp = 0, ans = 0;
stack<char> st;

int get_len()
{
	int len = 0;
	while (!st.empty() && st.top() != '(')
	{
		if (st.top() == ')')
		{
			st.pop();
			len += get_len();
		}
		else
		{
			st.pop();
			len++;
		}
	}

	st.pop();
	len = (st.top() - '0') * len;
	st.pop();

	return len;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	// freopen("input.txt", "r", stdin);

	cin >> ziped_s;

	for (int i = 0; i < ziped_s.size(); i++)
		st.push(ziped_s[i]);

	while (!st.empty())
	{
		if (st.top() == ')')
		{
			st.pop();
			ans += get_len();
		}
		else
		{
			st.pop();
			ans++;
		}
	}

	cout << ans;

	return 0;
}