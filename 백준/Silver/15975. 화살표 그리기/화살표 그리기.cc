#include <bits/stdc++.h>
#define INF 0x3f3f3f3f

using namespace std;

int N;
vector<int> v[100001]; // 색 기준
long long ans;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    for (int i = 0; i < N; i++)
    {
        int x, y;

        cin >> x >> y;
        v[y].push_back(x);
    }

    for (int i = 0; i < N; i++)
        sort(v[i].begin(), v[i].end());

    for (int i = 0; i < N; i++)
    {
        if (v[i].size() <= 1)
            continue;

        for (int j = 0; j < v[i].size(); j++)
        {
            if (j == 0)
                ans += v[i][j + 1] - v[i][j];
            else if (j == v[i].size() - 1)
                ans += v[i][j] - v[i][j - 1];
            else
                ans += min((v[i][j + 1] - v[i][j]), (v[i][j] - v[i][j - 1])); // 앞, 뒤 중 차이가 작은 것 선택
        }
    }

    cout << ans;

    return 0;
}