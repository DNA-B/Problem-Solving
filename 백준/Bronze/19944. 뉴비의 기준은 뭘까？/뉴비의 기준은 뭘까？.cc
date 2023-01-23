#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, m;
    
    cin >> n >> m;

    if (m >= 1 && m <= 2)
        cout << "NEWBIE!";
    else if (m <= n && m > 2)
        cout << "OLDBIE!";
    else
        cout << "TLE!";

	return 0;
}