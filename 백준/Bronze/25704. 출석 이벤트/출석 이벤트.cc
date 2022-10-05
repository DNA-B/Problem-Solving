#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n = 0;
    int price = 0;
    int f, t, ft, tt;
    int sale = 0;

    cin >> n >> price;

    if (n < 5)
    {
        sale = price;
    }
    else if (n >= 5 && n < 10)
    {
        sale = price - 500;
    }
    else if (n >= 10 && n < 15)
    {
        f = price - 500;
        t = price - (price * 0.1);
        sale = min(f, t);
    }
    else if (n >= 15 && n < 20)
    {
        f = price - 500;
        t = price - (price * 0.1);
        ft = price - 2000;
        sale = min({ f, t, ft });
    }
    else if (n >= 20)
    {
        f = price - 500;
        t = price - (price * 0.1);
        ft = price - 2000;
        tt = price - (price * 0.25);
        sale = min({ f, t, ft, tt});
    }

    if (sale <= 0)
        cout << 0;
    else
        cout << sale;

    return 0;
}