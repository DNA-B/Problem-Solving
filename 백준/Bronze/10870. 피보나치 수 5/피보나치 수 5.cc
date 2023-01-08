#include <bits/stdc++.h>

using namespace std;

int mem[21];
int n;

int fibo(int k)
{
    if (k == 0)
        return 0;

    if (k == 1)
        return 1;

    if (mem[k] != 0)
        return mem[k];

    mem[k] = fibo(k - 1) + fibo(k - 2);
    return mem[k];
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    mem[0] = 0;
    mem[1] = 1;

    cin >> n;
    cout << fibo(n);

    return 0;
}