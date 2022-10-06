#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int l, p;
	int sang = 0;
	int article[5];

	cin >> l >> p;
	sang = l * p;

	for (int i = 0; i < 5; i++)
	{
		cin >> article[i];
		cout << article[i] - sang << " ";
	}
	return 0;
}