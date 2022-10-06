#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int h, m, s, d;
	cin >> h >> m >> s >> d;
	cout << (h + (m + (s + d) / 60) / 60) % 24 << " " << (m + (s + d) / 60) % 60 << " " << (s + d) % 60;


	return 0;
}