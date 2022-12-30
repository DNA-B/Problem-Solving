#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    long long score = 0;
    long long n;

    cin >> n;

    while (n != 1)
    {
        if (n % 2 == 0)
        {
            score++;
            n /= 2;
        }
        else if (n % 2 != 0)
        {
            score++;
            n = (3 * n) + 1;
        }
    }

    cout << score;

    return 0;
}