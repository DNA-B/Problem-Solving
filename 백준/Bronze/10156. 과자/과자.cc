#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

    int k, n, m;
    cin >> k >> n >> m;
    if (k * n > m)
        cout << k * n - m << '\n';
    else
        cout << "0" << '\n';
	return 0;
}