#include <bits/stdc++.h>

using namespace std;

long long mem[21];

long long fact(int n)
{
    if (n == 0)
        return 1;

    if (mem[n] != 0)
        return mem[n];

    mem[n] = n * fact(n - 1);
    return mem[n];
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    
    mem[0] = 1;
    mem[1] = 1;

    cin >> n;
    cout << fact(n);

    return 0;
}