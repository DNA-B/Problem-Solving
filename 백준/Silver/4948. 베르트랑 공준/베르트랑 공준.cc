#include <bits/stdc++.h>

using namespace std;

bool is_not_prime[246913];

void era(int n)
{
    is_not_prime[1] = true;

    for (int i = 2; i < sqrt(n); i++)
    {
        if (is_not_prime[i])
            continue;

        for (int j = i + i; j <= n; j += i)
            is_not_prime[j] = true;
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    int cnt = 0;

    era(246913);

    while(1)
    {
        cin >> n;

        if (n == 0)
            return 0;

        for (int i = n + 1; i <= 2 * n; i++)
        {
            if (!is_not_prime[i])
                cnt++;
        }
        
        cout << cnt << "\n";
        cnt = 0;
    }

    return 0;
}