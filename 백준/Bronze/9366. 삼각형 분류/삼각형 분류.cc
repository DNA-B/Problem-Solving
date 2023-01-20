#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

	int t;
	int a, b, c;
	int total;

	cin >> t;

	for (int i = 1; i <= t; i++)
	{
		cin >> a >> b >> c;
		total = a + b + c;

		if (total - max({ a,b,c }) <= max({ a,b,c }))
			cout << "Case #" << i << ": invalid!" << "\n";
		else if (a == b && b == c)
			cout << "Case #" << i << ": equilateral" << "\n";
		else if ((a == b && b != c) || (a == c && c != b) || (b == c && c != a))
			cout << "Case #" << i << ": isosceles" << "\n";
		else if(a != b && a != c && b != c)
			cout << "Case #" << i << ": scalene" << "\n";
	}

	return 0;
}