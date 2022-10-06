#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	int x, y;
	
	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		cin >> x >> y;
		cout << "Case #" << i << ": " << x + y << "\n";
	}
	return 0;
}