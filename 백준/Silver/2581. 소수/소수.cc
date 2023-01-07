#include <bits/stdc++.h>

using namespace std;

bool arr[10001];
int min_prime = 10001;
int sum_prime = 0;

void era(int m)
{
    arr[0] = true;
    arr[1] = true;
    for (int i = 2; i < sqrt(m); i++)
    {
        if (arr[i] == true)
            continue;

        for (int j = i + i; j <= m; j += i)
            arr[j] = true;
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;

    cin >> n >> m;
    era(m);

    for (int i = n; i <= m; i++)
    {
        if (arr[i] == false)
        {
            if (min_prime > i)
                min_prime = i;

            sum_prime += i;
        }
    }

    if (sum_prime == 0)
        cout << -1;
    else
        cout << sum_prime << "\n" << min_prime;

    return 0;
}