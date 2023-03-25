#include<bits/stdc++.h>

using namespace std;

const int INF = 0x3f3f3f3f;
int N, M;
int board[101][101];
int d[101][101];
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int dijk(pair<int, int> st, pair<int, int> en)
{
    priority_queue <
        tuple<int, int, int>, 
        vector <tuple<int, int, int>>,
        greater<tuple<int, int, int>>
    > pq;

    d[st.first][st.second] = 0;
    pq.push({ 0, st.first, st.second });

    while (!pq.empty())
    {
        auto cur = pq.top();
        int w = get<0>(cur); // 벽을 부수는 횟수가 비용
        int x = get<1>(cur);
        int y = get<2>(cur);
        pq.pop();

        if (d[x][y] != w)
            continue;

        for (int dir = 0; dir < 4; dir++)
        {
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            int nw = w + board[nx][ny];

            if (nx < 1 || nx > N || ny < 1 || ny > M)
                continue;

            if (nw < d[nx][ny]) // 이미 방문 했어도 비용이 더 적으면 갱신
            {
                d[nx][ny] = nw;
                pq.push({ nw, nx, ny });
            }
        }
    }
    return d[en.first][en.second];
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> M >> N;

    for (int i = 1; i <= N; i++)
        fill(d[i] + 1, d[i] + M + 1, INF);

    string str;

    for (int i = 1; i <= N; i++)
    {
        cin >> str;

        for (int j = 1; j <= M; j++)
            board[i][j] = str[j - 1] - '0';
    }

    cout << dijk({ 1, 1 }, { N, M });

    return 0;
}