#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define MOD 123456789

using namespace std;

int N;
int mem[40001];
bool is_not_prime[40001];
vector<int> prime;

void era(int n)
{
    for (int i = 2; i <= n; i++)
    {
        if (is_not_prime[i] == true)
            continue;

        for (int j = i * i; j <= n; j += i)
            is_not_prime[j] = true;
    }
}

void insert_prime(int n)
{
    for (int i = 2; i <= N; i++)
    {
        if (is_not_prime[i] == false)
            prime.push_back(i);
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    era(N);
    insert_prime(N);

    mem[0] = 1; // 나만 고르는 경우
    for (int i = 0; i < prime.size(); i++)
        for (int j = prime[i]; j <= N; j++)
            mem[j] = (mem[j] % MOD) + (mem[j - prime[i]] % MOD);

    cout << mem[N] % MOD;

    return 0;
}
