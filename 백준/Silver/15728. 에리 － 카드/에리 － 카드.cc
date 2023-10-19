#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define MAX 4e9
#define MOD 1000000000

using namespace std;

int N, K;
vector<tuple<int, int, int>> v; // {점수, (공유, 팀)}
map<int, bool> is_used; // {팀, 사용 여부}
int share[101];
int team[101];

bool cmp(tuple<int, int, int>& a, tuple<int, int, int>& b)
{
    if (get<0>(a) == get<0>(b))
        return get<2>(a) < get<2>(b);
    else
        return get<0>(a) > get<0>(b);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> K;

    for (int i = 0; i < N; i++)
        cin >> share[i];
    for (int i = 0; i < N; i++)
        cin >> team[i];

    for (int i = 0; i < N; i++)
    {
        int score;
        for (int j = 0; j < N; j++)
        {
            score = share[i] * team[j];
            v.push_back({ score, share[i], team[j] });
        }
    }

    sort(v.begin(), v.end(), cmp);

    int cnt = 0;
    for (auto item : v)
    {
        if (!is_used[get<2>(item)])
        {
            if (cnt == K)
            {
                cout << get<0>(item);
                break;
            }

            is_used[get<2>(item)] = true;
            cnt++;
        }
    }

    return 0;
}
