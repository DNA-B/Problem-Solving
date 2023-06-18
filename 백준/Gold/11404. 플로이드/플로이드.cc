#include <bits/stdc++.h>
#define INF 0x3f3f3f3f

using namespace std;

int d[101][101];
int N, M;

int main(void) 
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    
    for (int i = 1; i <= N; i++) // init
        fill(d[i], d[i] + 1 + N, INF);
    
    while (M--) 
    {
        int a, b, c;
        cin >> a >> b >> c;
        d[a][b] = min(d[a][b], c);
    }

    for (int i = 1; i <= N; i++) // 자기 자신 0으로
        d[i][i] = 0;

    
    for (int k = 1; k <= N; k++)
        for (int i = 1; i <= N; i++)
            for (int j = 1; j <= N; j++)
                if (d[i][j] > d[i][k] + d[k][j]) // k 거치는 경로가 더 작을 경우 갱신
                    d[i][j] = d[i][k] + d[k][j];


    for (int i = 1; i <= N; i++) 
    {
        for (int j = 1; j <= N; j++) 
        {
            if (d[i][j] == INF)
                cout << "0 ";
            else 
                cout << d[i][j] << ' ';
        }
        cout << '\n';
    }

    return 0;
}