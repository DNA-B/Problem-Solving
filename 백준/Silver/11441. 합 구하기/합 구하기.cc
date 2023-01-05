#include <bits/stdc++.h>

using namespace std;

vector <int> v(100001);
vector <int> v_sum(100001);

int n, m;
int st, en;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    v.resize(n + 1);
    v_sum.resize(n + 1);

    v[0] = 0;
    for (int i = 1; i <= n; i++)
        cin >> v[i];

    v_sum[0] = 0;
    for (int i = 1; i <= n; i++)
        v_sum[i] = v[i] + v_sum[i - 1];

    cin >> m;

    while (m--)
    {
        cin >> st >> en;
        cout << v_sum[en] - v_sum[st - 1] << "\n";
    }

    return 0;
}