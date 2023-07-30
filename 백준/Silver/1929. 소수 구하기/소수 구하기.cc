#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define MOD 123456789

using namespace std;

int M, N;
int mem[1000001];
bool is_not_prime[1000001];

void era(int n)
{
    for (int i = 2; i <= sqrt(n); i++)
    {
        if (is_not_prime[i] == true)
            continue;

        for (int j = i * i; j <= n; j += i)
            is_not_prime[j] = true;
    }
}

void print_prime(int m, int n)
{
    for (int i = m; i <= n; i++)
    {
        if (is_not_prime[i] == false)
            cout << i << "\n";
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> M >> N;

    is_not_prime[1] = true;
    era(N);
    print_prime(M, N);

    return 0;
}
