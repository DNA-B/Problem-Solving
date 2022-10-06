#include <bits/stdc++.h>

using namespace std;

int main() 
{
    int f[4];
    int a=0, b=0;
    for (int i = 0; i < 4; i++)
    {
        cin >> f[i];
    }
    cout << abs(f[0] + f[3] - f[1] - f[2]);
}
