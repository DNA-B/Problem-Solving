#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

using namespace std;

int ans = 0;
string s;
map<char, pair<int, int>> m; // <이름, <st, en>>

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	// freopen("input.txt", "r", stdin);

	cin >> s;

	for (int i = 0; i < s.size(); i++) // 시작점, 끝점 초기화
	{
		if (m.find(s[i]) == m.end())
			m[s[i]].first = i;
		else
			m[s[i]].second = i;
	}

	for (int i = 'A'; i <= 'Z'; i++)
	{
		for (int j = 'A'; j <= 'Z'; j++)
		{
			if (i == j)
				continue;
			if (m[i].first < m[j].first && m[j].first < m[i].second && m[i].second < m[j].second)
				ans++;
		}
	}

	cout << ans;

	return 0;
}