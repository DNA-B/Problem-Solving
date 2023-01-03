#include <bits/stdc++.h>

using namespace std;

vector <int> v(101);
int n, x;
int cnt = 0;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        
        if (v[x] == 0)
            v[x]++;
        else
            cnt++;
    }

    cout << cnt;

    return 0;
}