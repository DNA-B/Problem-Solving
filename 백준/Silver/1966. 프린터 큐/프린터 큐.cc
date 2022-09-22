#include <bits/stdc++.h>

using namespace std;

bool compare(int x, int y)
{
    return x > y;
}

int main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    int n, m;
    int imp;
    int count = 0;

    cin >> t;

    while (t--)
    {
        queue<pair<int, int>> q; // 중요도 큐
        vector<int> v; // 정렬 큐
        count = 0;

        cin >> n >> m;

        for (int i = 0; i < n; i++)
        {
            cin >> imp;
            q.push({ imp, i });
            v.push_back(imp);
        }

        sort(v.begin(), v.end(), compare); // 중요도 내림차순 정렬

        while (!q.empty() && !v.empty())
        {
            if (q.front().first == v[0]) // v[0]은 max값
            {
                if (q.front().second == m) // 만약 순서까지 같다면 break
                {
                    count++;
                    break;
                }
                q.pop();
                v.erase(v.begin());
                count++;
            }
            else 
            {
                q.push(q.front());
                q.pop();
            }
        }
        cout << count << "\n";
    }
    return 0;
}