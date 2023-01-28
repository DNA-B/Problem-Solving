#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, m;
    
    cin >> n >> m;

    n /= 2;
    m /= 2;

    cout << min(n, m);

	return 0;
}