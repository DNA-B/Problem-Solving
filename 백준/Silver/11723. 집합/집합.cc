#include <bits/stdc++.h>

using namespace std;

int main() // 비트마스크
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int s = 0;
    int n;
    int rep;
    string order;

    cin >> rep;

    for (int i = 0; i < rep; i++)
    {
        cin >> order;

        if (order == "add")
        {
            cin >> n;

            if (s & (1 << n)) continue;
            else (s |= (1 << n));
        }
        else if (order == "remove")
        {
            cin >> n;

            if (!(s & (1 << n))) continue;
            else (s &= ~(1 << n));
        }
        else if (order == "check")
        {
            cin >> n;
            if ((s & (1 << n))) cout << "1\n";
            else cout << "0\n";
        }
        else if (order == "toggle")
        {
            cin >> n;
            s ^= (1 << n);
        }
        else if (order == "empty")
        {
            s = 0;
        }
        else if (order == "all")
        {
            s = (1 << 21) - 1;
        }
    }
    
    return 0;
}