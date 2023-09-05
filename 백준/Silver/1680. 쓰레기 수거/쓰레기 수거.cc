#include <bits/stdc++.h>
#define INF 0x3f3f3f3f

using namespace std;

int T;
int W, N;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> T;

    while (T--)
    {
        int total_dist = 0;
        int cur_w = 0;
        vector<pair<int, int>> v;

        cin >> W >> N; // {차 용량, 쓰레기장 수}

        for (int i = 0; i < N; i++)
        {
            int xi, wi;

            cin >> xi >> wi;
            v.push_back({ xi, wi }); // {거리, 쓰레기양}
        }

        for (int i = 0; i < v.size(); i++)
        {
            if (cur_w + v[i].second > W)
            {
                total_dist += v[i].first - v[i - 1].first;
                total_dist += v[i].first;
                cur_w = 0;
            }

            if (cur_w == 0)
            {
                total_dist += v[i].first;
                cur_w += v[i].second;
            }
            else
            {
                total_dist += v[i].first - v[i - 1].first;
                cur_w += v[i].second;
            }

            if (cur_w == W || i == (v.size() - 1))
            {
                total_dist += v[i].first;
                cur_w = 0;
            }
        }

        cout << total_dist << "\n";
    }
    return 0;
}
