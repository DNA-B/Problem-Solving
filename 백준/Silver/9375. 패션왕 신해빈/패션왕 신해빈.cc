#include<bits/stdc++.h>
#define INF 0x3f3f3f3f

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T, n;
    map<string, int> m;
    string clothes_name, clothes_type;
    int ans = 1;

    cin >> T;

    while (T--)
    {
        m = {};
        ans = 1;

        cin >> n;

        for (int i = 0; i < n; i++)
        {
            cin >> clothes_name >> clothes_type;
            m[clothes_type] += 1;
        }

        for (auto item : m)
            ans *= item.second + 1; // [입는 경우 + 안 입는 경우(+1)]

        cout << ans - 1 << "\n"; // 알몸인 경우 (-1)
    }

    return 0;
}