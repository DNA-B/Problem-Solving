#include <bits/stdc++.h>
#define INF 0x3f3f3f3f

using namespace std;

int a0, a1;
int c, n0;

int f(int n)
{
    return (a1 * n) + a0;
}

int g(int n)
{
    return c * n;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> a1 >> a0;
    cin >> c;
    cin >> n0;

    bool flag = true;
    for (int i = n0; i <= 100; i++)
        if (!(f(i) <= g(i)))
            flag = false;

    if (flag)
        cout << 1;
    else
        cout << 0;

    return 0;
}
