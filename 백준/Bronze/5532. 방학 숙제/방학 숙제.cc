#include <bits/stdc++.h>

using namespace std;

int main() 
{
    int l, a, b, c, d, freeday;
    
    cin >> l >> a >> b >> c >> d;
    
    freeday = l - max(ceil(((double)a/c)), ceil(((double)b/d)));
    cout<<freeday;
    return 0;
}