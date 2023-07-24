#include <bits/stdc++.h>
#define INF 0x3f3f3f3f

using namespace std;

vector<pair<int, int>>v;
int N, M;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;

    int dot;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> dot;

            if (dot == 1)
                v.push_back({ i,j });
        }
    }

    int x1, x2, y1, y2;
    x1 = v[0].first;
    y1 = v[0].second;
    x2 = v[1].first;
    y2 = v[1].second;

    cout << abs(x2 - x1) + abs(y2 - y1);

    return 0;
}
