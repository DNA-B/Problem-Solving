#include<bits/stdc++.h>
#define INF 0x3f3f3f3f

using namespace std;

int R, C;
char kayak[52][52];
vector<pair<int, int>> v;
int ans[10];
int grade = 1;

bool cmp(pair<int, int>& p1, pair<int, int>& p2)
{
    return p1.second < p2.second;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> R >> C;

    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            cin >> kayak[i][j];

            if (j > 0 && j < C)
            {
                if ('1' <= kayak[i][j - 1] && kayak[i][j - 1] <= '9')
                {
                    if (kayak[i][j] < '1' || '9' < kayak[i][j])
                    {
                        v.push_back({ kayak[i][j - 1] - '0', C - j });
                    }
                }
            }
        }
    }

    sort(v.begin(), v.end(), cmp);

    for (int i = 0; i < 9; i++)
    {
        if (i > 0)
        {
            if (v[i - 1].second < v[i].second)
                grade++;
        }

        ans[v[i].first] = grade;
    }

    for (int i = 1; i < 10; i++)
        cout << ans[i] << "\n";

    return 0;
}