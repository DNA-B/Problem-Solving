#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;

    cin >> n;

    if (n == 1)
        return 0;

    while (n > 1)
    {
        for (int i = 2; i <= n; i++)
        {
            if (n % i == 0)
            {
                n /= i;
                cout << i << "\n";
                break;
            }            
        }

    }

    return 0;
}