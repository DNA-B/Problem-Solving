#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int maps[301][301];
bool visit[301][301];

int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int row, col; cin>>row>>col;
    for (int i=0; i<col; ++i)
    {
        for (int j=0; j<row; ++j)
        {
            int v; cin>>v;
            maps[i][j] = v;
        }   
    }


    queue<pair<int, int>> q;
    q.push(make_pair(0, 0));
    visit[0][0] = true;

    while (!q.empty())
    {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();

        for (int ay=1; ay>=0; --ay)
        {
            int ax = 1-ay;

            int dy = y+ay;
            int dx = x+ax;
            if (dy<0 || dx<0 || dy>=col || dx>=row) continue;
            if (maps[dy][dx] == 0 || visit[dy][dx]) continue;

            q.push(make_pair(dy, dx));
            visit[dy][dx] = true;
        }
    }

    cout<<(visit[col-1][row-1] ? "Yes" : "No");
}