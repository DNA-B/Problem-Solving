#include <bits/stdc++.h>

using namespace std;

vector<int> v(3);
int d1, d2;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> v[0] >> v[1] >> v[2];
    sort(v.begin(), v.end());

    d1 = v[1] - v[0];
    d2 = v[2] - v[1];

    if (d1 > d2) 
        cout << v[0] + d2;
    else if
        (d1 == d2) cout << v[2] + d1;
    else 
        cout << v[1] + d1;

	return 0;
}