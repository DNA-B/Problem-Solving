#include <bits/stdc++.h>

using namespace std;

bool cmp(string str1, string str2)
{
	if (str1.length() == str2.length())
	{
		return str1 < str2;
	}
	else
	{
		return str1.length() < str2.length();
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	vector<string> v;
	string str;
	int num;

	cin >> num;

	for (int i = 0; i < num; i++)
	{
		cin >> str;
		v.push_back(str);
	}

	sort(v.begin(), v.end(), cmp); // c++ sort()는 O(nlogn)의 시간복잡도

	for (int i = 0; i < num; i++)
	{
		if (i > 0)
		{
			if (v[i] == v[i - 1])
			{
				continue;
			}
		}
		cout << v[i] << "\n";
	}
	return 0;
}