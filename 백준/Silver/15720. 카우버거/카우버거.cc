#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define MAX 4e9

using namespace std;

int B, C, D;
int pre_price = 0, post_price = 0;
int b[1001], c[1001], d[1001];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> B >> C >> D;

    for (int i = 0; i < B; i++)
        cin >> b[i];

    for (int i = 0; i < C; i++)
        cin >> c[i];

    for (int i = 0; i < D; i++)
        cin >> d[i];

    sort(b, b + B, greater<>());
    sort(c, c + C, greater<>());
    sort(d, d + D, greater<>());

    int len = max({ B, C, D });
    for (int i = 0; i < len; i++)
    {
        pre_price += b[i] + c[i] + d[i];

        if (b[i] == 0 || c[i] == 0 || d[i] == 0)
            post_price += b[i] + c[i] + d[i];
        else
            post_price += (b[i] + c[i] + d[i]) * 0.9;
    }

    cout << pre_price << "\n" << post_price;

    return 0;
}
