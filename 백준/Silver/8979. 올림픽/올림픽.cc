#include<bits/stdc++.h>
#define INF 0x3f3f3f3f

using namespace std;

int N, K;
tuple<int, int, int, int> t[1002];
int ans[1002];
int v1, v2, v3, v4;

bool cmp(int i, int j)
{
    if (get<1>(t[i]) == get<1>(t[j]))
    {
        if (get<2>(t[i]) == get<2>(t[j]))
        {
            return get<3>(t[i]) > get<3>(t[j]);
        }
        return get<2>(t[i]) > get<2>(t[j]);
    }
    return get<1>(t[i]) > get<1>(t[j]);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> K;

    for (int i = 1; i <= N; i++)
    {
        cin >> v1 >> v2 >> v3 >> v4;
        t[i] = make_tuple(v1, v2, v3, v4);
    }

    for (int i = 1; i < N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            if (get<1>(t[i]) == get<1>(t[j]) && get<2>(t[i]) == get<2>(t[j]) && get<3>(t[i]) == get<3>(t[j]))
                continue;

            if (cmp(i, j)) // true면 t[i]의 순위가 더 높음
                ans[get<0>(t[i])]++;
            else // false면 t[j]의 순위가 더 높음
                ans[get<0>(t[j])]++;
        }
    }

    cout << ans[K] + 1;

    return 0;
}