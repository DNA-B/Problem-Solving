#include <bits/stdc++.h>

using namespace std;

int N, M;
string k, v;
map<string, string> m;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N >> M;

    while (N--)
    {
        cin >> k >> v;
        m[k] = v;
    }

    while (M--)
    {
        cin >> k;
        cout << m[k] << "\n";
    }

    return 0;
}