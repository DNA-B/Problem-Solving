#include <bits/stdc++.h>

using namespace std;

#define PI 3.141592
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int s, m, l;
	int total = 0;

	cin >> s >> m >> l;

	total = s + (m * 2) + (l * 3);

	if (total >= 10) cout << "happy";
	else cout << "sad";

	return 0;
}