#include<bits/stdc++.h>
#define INF 0x3f3f3f3f

using namespace std;

int T, N, x;
vector<int> v(1002); // 등수 매기기용
vector<vector<int>> team_rank(201);
vector<pair<int, int>> score;
map<int, int> m; // { 팀, 인원 }
pair<int, int> ans = { 0, INF };

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> T;

    while (T--)
    {
        v = vector<int>(1002);
        team_rank = vector<vector<int>>(201);
        score = vector<pair<int, int>>();
        m.clear();
        ans = { 0, INF };

        cin >> N;

        for (int i = 1; i <= N; i++)
        {
            cin >> x;
            v[i] = x;
            m[x]++;
        }

        for (auto item : m)
        {
            if (item.second < 6) // 인원 모자르면 등수에서 제외
                v.erase(remove(v.begin(), v.end(), item.first), v.end());
        }

        for (int i = 1; v[i] != 0; i++)
            team_rank[v[i]].push_back(i);

        /*
        for (int i = 1; i <= 200; i++)
        {
            if (team_rank[i].size() == 0)
                continue;

            cout << i << " : ";
            for (int j = 0; j < team_rank[i].size(); j++)
            {
                cout << team_rank[i][j] << " ";
            }
            cout << "\n";
        }
        */

        for (int i = 1; i <= 200; i++)
        {
            if (team_rank[i].size() == 0)
                continue;

            score.push_back({ i, accumulate(team_rank[i].begin(), team_rank[i].begin() + 4, 0) }); // {팀, 상위 4명 점수}
            // cout << i << " score : " << accumulate(team_rank[i].begin(), team_rank[i].begin() + 4, 0) << "\n";
        }

        for (int i = 0; i < score.size(); i++)
        {
            if (score[i].second < ans.second)
            {
                ans = { score[i].first, score[i].second };
            }
            else if (score[i].second == ans.second)
            {
                if (team_rank[score[i].first][4] < team_rank[ans.first][4])
                    ans = { score[i].first, score[i].second };
                else
                    ans = { ans.first, ans.second };
            }
        }
        
        cout << ans.first << "\n";   
    }

    return 0;
}