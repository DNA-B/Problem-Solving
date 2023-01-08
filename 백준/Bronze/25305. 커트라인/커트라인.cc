#include <bits/stdc++.h>

using namespace std;

vector<int> v(1000);
int n, k;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> k;
    v.resize(n);

    for (int i = 0; i < n; i++)
        cin >> v[i];

    sort(v.begin(), v.end(), greater<>());

    cout << v[k - 1];
    
    return 0;
}