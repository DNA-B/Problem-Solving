#include <bits/stdc++.h>

using namespace std;

int N, K, C, R;
int base[100001];
int s[100001];
int p[100001];
map<int, int> m;
long long ans = 0, fatigue = 0, combo = 0;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> K >> C >> R;

    for (int i = 1; i <= K; i++)
        cin >> base[i];
    for (int i = 1; i <= K; i++)
        cin >> s[i];
    for (int i = 1; i <= K; i++)
        cin >> p[i];


    for (int i = 0; i < N; i++)
    {
        int l;

        cin >> l;

        if (l == 0)
        {
            fatigue -= R;
            combo = 0;

            if (fatigue < 0)
                fatigue = 0;

            continue;
        }

        ans += base[l] * ((1 + ((double)(combo * C) / 100))) * (1 + ((double)(m[l] * s[l]) / 100));
        combo++;
        m[l]++;
        fatigue += p[l];

        if (fatigue > 100)
        {
            cout << -1;
            return 0;
        }
    }

    cout << ans;

    return 0;
}
