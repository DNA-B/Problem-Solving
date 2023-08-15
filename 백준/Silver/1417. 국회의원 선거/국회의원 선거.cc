#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define PI 3.1415927

using namespace std;

int N, M;
int cur_dasom;
int ans = 0;
vector <pair<int, int>> v; // <표, 기호>

bool cmp(pair<int, int>& a, pair<int, int>& b)
{
    return a.second > b.second;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    for (int i = 1; i <= N; i++)
    {
        cin >> M;

        if (i == 1)
            cur_dasom = M;
        else
            v.push_back({ i, M });
    }

    sort(v.begin(), v.end(), cmp);
    while (!v.empty() && cur_dasom <= v[0].second)
    {
        v[0].second -= 1;
        ans++;
        cur_dasom++;
        sort(v.begin(), v.end(), cmp);
    }


    cout << ans;

    return 0;
}
