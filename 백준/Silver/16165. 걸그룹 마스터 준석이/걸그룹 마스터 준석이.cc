#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

using namespace std;

int N, M;
map<string, set<string>> team; // {팀 이름, 이름}
map<string, string> member; // {이름, 팀 이름}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	// freopen("input.txt", "r", stdin);

	cin >> N >> M;

	while (N--)
	{
		int team_n;
		string team_name, member_name;

		cin >> team_name >> team_n;

		while (team_n--)
		{
			cin >> member_name;

			team[team_name].insert(member_name);
			member[member_name] = team_name;
		}
	}

	while (M--)
	{
		int order;
		string question;

		cin >> question >> order;

		switch (order)
		{
		case 0:
			for (auto mamber_name : team[question])
				cout << mamber_name << "\n";
			break;
		case 1:
			cout << member[question] << "\n";
			break;
		}
	}

	return 0;
}