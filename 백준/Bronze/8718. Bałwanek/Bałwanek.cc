#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long x, k, a, b, c;
    cin >> x >> k;
    
    if(7000 * k <= 1000 * x) a = 7000 * k;
    if(3500 * k <= 1000 * x) b = 3500 * k;
    if(1750 * k <= 1000 * x) c = 1750 * k;
    
    cout << max({a,b,c});
    
    return 0;
}