#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, m, k;
    cin  >> k;
    
    for(int i = 0; i < k; i++)
    {
        cin >> n >> m;
        cout << n*m/2 << "\n";
    }
    
    return 0;
}