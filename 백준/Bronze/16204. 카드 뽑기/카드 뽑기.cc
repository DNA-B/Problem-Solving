#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, m, k;
    int o, x;

    cin >> n >> m >> k;

    o = k < m ? k : m;
    x = (n - k) < (n - m) ? n - k : n - m;

    cout << o + x;

	return 0;
}