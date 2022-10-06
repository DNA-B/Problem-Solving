#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int big, small;
	int total;

	cin >> big >> small;
	total = (big * 8) + (small * 3);
	cout << total - 28;
	
	return 0;
}