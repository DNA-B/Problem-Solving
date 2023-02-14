#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int a, b, c;
    int t;
    int res = 0;

    cin >> t;

    while (t--)
    {
        cin >> a >> b >> c;

        for (int i = 1; i <= a; i++)
        {
            for (int j = 1; j <= b; j++)
            {
                for (int k = 1; k <= c; k++)
                {
                    if (i % j == j % k && j % k == k % i)
                        res++;
                }
            }
        }

        cout << res << "\n";
        res = 0;
    }
    
    return 0;
}