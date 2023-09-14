#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define MAX 4e9

using namespace std;

int T;

bool is_prime(long long n)
{
    for (int i = 2; i <= sqrt(n); i++)
        if (n % i == 0)
            return false;

    return true;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> T;

    while (T--)
    {
        long long n;

        cin >> n;

        if (n == 0 || n == 1)
            cout << 2 << "\n";
        else
        {
            while (!is_prime(n))
                n++;

            cout << n << "\n";
        }
    }


    return 0;
}
