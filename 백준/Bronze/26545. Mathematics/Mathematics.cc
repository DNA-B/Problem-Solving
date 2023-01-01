#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n = 0, sum = 0;
    int x = 0;

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> x;
        sum += x;
    }

    cout << sum;

    return 0;
}