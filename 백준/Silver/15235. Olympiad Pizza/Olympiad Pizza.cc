#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define MAX_GAP 500000

using namespace std;


int N;
int timer = 0;
int total_time[1002];
queue<pair<int, int>> q;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    for (int i = 0; i < N; i++)
    {
        int x;

        cin >> x;
        q.push({ i, x });
    }

    while (!q.empty())
    {
        auto cur = q.front();
        q.pop();
        timer++;
        cur.second--;

        if (cur.second == 0)
            total_time[cur.first] = timer;
        else
            q.push(cur);
    }

    for (int i = 0; i < N; i++)
        cout << total_time[i] << " ";

    return 0;
}
