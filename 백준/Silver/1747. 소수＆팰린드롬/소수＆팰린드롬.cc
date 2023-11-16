#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define MAX 10000000

using namespace std;

int N;
bool is_not_prime[MAX + 1];

void era()
{
    is_not_prime[1] = true;

    for (int i = 2; i < sqrt(MAX); i++)
    {
        if (is_not_prime[i])
            continue;

        for (int j = i * i; j <= MAX; j += i)
            is_not_prime[j] = true;
    }
}

bool is_palindrome(int n)
{
    string tmp = to_string(n);

    int len = tmp.length();

    for (int i = 0; i < len / 2; i++)
    {
        if (tmp[i] != tmp[(len - i) - 1])
            return false;
    }

    return true;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    era();

    for (int i = N; i <= MAX; i++)
    {
        if (!is_not_prime[i] && is_palindrome(i))
        {
            cout << i;
            return 0;
        }
    }

    return 0;
}
