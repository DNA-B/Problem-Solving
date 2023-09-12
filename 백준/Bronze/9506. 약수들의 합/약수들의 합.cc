#include <bits/stdc++.h>
#define INF 0x3f3f3f3f

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    while (true)
    {
        int n;
        int total = 1;
        vector<int> v;

        cin >> n;

        if (n == -1)
            break;

        for (int i = 2; i <= n / 2; i++)
        {
            if (n % i == 0)
            {
                v.push_back(i);
                total += i;
            }
        }

        if (total == n)
        {
            cout << n << " = 1";
            for (auto item : v)
                cout << " + " << item;
            cout << "\n";
        }
        else
            cout << n << " is NOT perfect.\n";
    }

    return 0;
}
