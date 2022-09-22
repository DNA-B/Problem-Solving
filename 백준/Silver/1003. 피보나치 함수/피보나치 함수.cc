#include <bits/stdc++.h>
#define IO ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

long long z[41] = { 0 };
long long o[41] = { 0 };

long long fiboz(int n)
{
    if (n == 0) return 1;
    if (n == 1) return 0;

    if (z[n] != 0) return z[n];
    else
    {
        z[n] = fiboz(n - 1) + fiboz(n - 2);
        return z[n];
    }
}

long long fiboo(int n)
{
    if (n == 0) return 0;
    if (n == 1) return 1;
    
    if (o[n] != 0) return o[n];
    else
    {
        o[n] = fiboo(n - 1) + fiboo(n - 2);
        return o[n];
    }
}

int main() 
{
    IO;
    
    int rep, n;

    cin >> rep;

    while (rep--)
    {
        cin >> n;

        fill(z, z + 41, 0);
        fill(o, o + 41, 0);

        cout << fiboz(n) << " " << fiboo(n) << "\n";
    }

    return 0;
}