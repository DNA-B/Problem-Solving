#include <bits/stdc++.h>
#define INF 0x3f3f3f3f

using namespace std;

string fact;

int factorial(int n)
{
    int res = 1;

    for (int i = n; i > 1; i--)
        res *= i;

    return res;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    while (1)
    {
        int ans = 0;
        cin >> fact;

        if (fact == "0")
            break;

        for (int i = 0; i < fact.length(); i++)
            ans += (fact[i] - '0') * factorial(fact.length() - i);

        cout << ans << "\n";
    }

    return 0;
}
