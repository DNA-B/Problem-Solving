#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int s, k, h;

	cin >> s >> k >> h;

	if (s + k + h >= 100)
	{
		cout << "OK";
	}
	else
	{
		if (min({ s,k,h }) == s)
		{
			cout << "Soongsil";
		}
		else if (min({ s,k,h }) == k)
		{
			cout << "Korea";
		}
		else
		{
			cout << "Hanyang";
		}
	}

	return 0;
}