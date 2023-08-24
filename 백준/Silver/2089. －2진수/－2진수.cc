#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;

long long N;

string negative_binary(long long n)
{
    string ans = "";

    while (n != 0)
    {
        long long q = n / -2;
        long long r = n % -2;

        if (r < 0)
        {
            q += 1;
            r += 2;
        }

        n = q;
        ans = to_string(r) + ans;
    }

    if (ans == "")
        ans = "0";

    return ans;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    cout << negative_binary(N);

    return 0;
}