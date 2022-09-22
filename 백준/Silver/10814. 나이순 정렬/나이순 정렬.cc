#include <bits/stdc++.h>

using namespace std;

bool compare(pair<int, string> v1, pair<int, string> v2)
{
	return	v1.first < v2.first;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	vector<pair<int, string>> v;
	string name;
	int age;
	int n;

	cin >> n;

	while (n--)
	{
		cin >> age >> name;
		v.push_back({ age, name });
	}

	stable_sort(v.begin(), v.end(), compare); // stable_sort는 같을 때 순서를 유지한다.
	
	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i].first << " " << v[i].second << "\n";
	}

	return 0;
}