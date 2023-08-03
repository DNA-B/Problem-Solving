#include <bits/stdc++.h>
#define INF 0x3f3f3f3f

using namespace std;

int N, G;
map<int, int> cnt;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    for (int i = 1; i <= N; i++)
    {
        cnt = {};
        cin >> G;

        int x;
        while (G--)
        {
            cin >> x;
            cnt[x]++;
        }

        for (auto item : cnt)
        {
            if (item.second == 1)
            {
                cout << "Case #" << i << ": " << item.first << "\n";
                break;
            }
        }
    }

    return 0;
}
