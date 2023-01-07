#include <bits/stdc++.h>

using namespace std;

bool is_not_prime[10001];

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

    int t, n;
    int min_sub = 10001;
    pair <int, int> p;

    cin >> t;

    era(10001);

    while (t--)
    {
        cin >> n;

        for (int i = 2; i <= n / 2; i++)
        {
            if (!is_not_prime[i] && !is_not_prime[n - i])
            {
                // i가 소수고 n - i도 소수인데
                    if ((n - i) - i < min_sub)
                    {
                        // 차가 가장 작은 pair 선택
                        min_sub = (n - i) - i;
                        p = { i, n - i };
                    }
            }
        }
        min_sub = 10001;
        cout << p.first << " " << p.second << "\n";
    }

    return 0;
}