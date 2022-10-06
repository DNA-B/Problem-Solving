#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int prize;

	cin >> prize;

	cout << prize - (int)(prize * 0.22) << "\n";
	cout << prize - (int)((prize * 0.2) * 0.22);
	return 0;
}