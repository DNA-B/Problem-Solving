#include <bits/stdc++.h>

using namespace std;

int main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int h, w, n;
    int res;
    int rep;

    cin >> rep;

    while (rep--)
    {
        cin >> h >> w >> n;

        if (n % h == 0)
            res = h * 100 + (n / h);
        else 
            res = (n % h) * 100 + (n / h) + 1;

        cout << res << "\n";
    }
   
    return 0;
}