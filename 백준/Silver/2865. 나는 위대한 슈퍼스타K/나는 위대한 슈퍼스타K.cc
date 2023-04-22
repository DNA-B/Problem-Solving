#include<bits/stdc++.h>

using namespace std;

int N, M, K, cnt = 0;
map<int, double> m;
int idx;
double s;
double ans = 0;

bool cmp(const pair<int, double> a, const pair<int, double>b)
{
    return a.second > b.second;
}

// 예선 N명 -> 본선 K명
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M >> K;

    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> idx >> s;

            if (m[idx] < s)
                m[idx] = s;
        }
    }

    vector<pair<int, double>> v(m.begin(), m.end());
    sort(v.begin(), v.end(), cmp);
    
    for (int i = 0; i < K; i++)
        ans += v[i].second;
    

    cout << fixed;
    cout.precision(1);
    cout << ans;

    return 0;
}