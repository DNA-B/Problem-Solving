#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	long long a, b, c;
	cin >> a >> b >> c;
    
	if (a + b - 2 * c >= 0) cout << a + b - 2 * c << endl;
	else cout << a + b << endl;
}