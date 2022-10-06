#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	string psw;

	cin >> n;

	
	while (n--)
	{
		cin >> psw;

		if (psw.length() >= 6 && psw.length() <= 9)
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