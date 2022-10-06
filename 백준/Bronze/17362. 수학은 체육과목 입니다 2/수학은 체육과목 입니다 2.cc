#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	n %= 8;
	cout << (n > 5 || n == 0 ? (10 - n) % 8 : n);

	return 0;
}