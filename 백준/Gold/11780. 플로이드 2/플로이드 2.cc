#include <bits/stdc++.h>
#define INF 0x3f3f3f3f

using namespace std;

int d[101][101];
int nxt[105][105];
int N, M;
vector<int> path; // u -> v로 가는 최단 경로 중 거치는 곳

int main(void) 
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    
    for (int i = 1; i <= N; i++)
        fill(d[i], d[i] + 1 + N, INF);
    
    while (M--) 
    {
        int a, b, c;
        cin >> a >> b >> c;
        d[a][b] = min(d[a][b], c);
        nxt[a][b] = b;
    }

    for (int i = 1; i <= N; i++)
        d[i][i] = 0;

    
    for (int k = 1; k <= N; k++)
        for (int i = 1; i <= N; i++)
            for (int j = 1; j <= N; j++)
                if (d[i][j] > d[i][k] + d[k][j])
                {
                    d[i][j] = d[i][k] + d[k][j];
                    nxt[i][j] = nxt[i][k]; // i -> j 최단경로 중 k를 거친다.
                }


    for (int i = 1; i <= N; i++) 
    {
        for (int j = 1; j <= N; j++) 
        {
            if (d[i][j] == INF) // 경로 없음
                cout << "0 ";
            else 
                cout << d[i][j] << ' ';
        }
        cout << '\n';
    }


    for (int i = 1; i <= N; i++) 
    {
        for (int j = 1; j <= N; j++) 
        {
            if (d[i][j] == 0 || d[i][j] == INF) // 자기 자신 or 경로 없음
            {
                cout << "0\n";
                continue;
            }

            path = {};
            int st = i;

            while (st != j) 
            {
                path.push_back(st);
                st = nxt[st][j];
            }
            path.push_back(j);

            cout << path.size() << ' ';
            for (auto x : path) 
                cout << x << ' ';
            cout << "\n";
        }
    }

    return 0;
}