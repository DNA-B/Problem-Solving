#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int s1, s2, s3, s4;
	int total = 0;

	cin >> s1 >> s2 >> s3 >> s4;
	total = s1 + s2 + s3 + s4;

	cout << total / 60 << "\n" << total % 60;
	return 0;
}