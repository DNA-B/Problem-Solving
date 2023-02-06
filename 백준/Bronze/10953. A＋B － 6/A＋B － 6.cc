#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int a, b;
    char comma;
    int t;

    cin >> t;

    while (t--)
    {
        cin >> a >> comma >> b;
        cout << a + b << "\n";
    }
    
    return 0;
}