#include <bits/stdc++.h>

using namespace std;

/*
BOJ 17352번 : 여러분의 다리가 되어 드리겠습니다!
- 원래는 모든 다리가 이어져 있었다.
- 하나가 없어졌으므로 두 개의 덩어리로 나눠진다.
- 그렇다면 main에서 bfs는 두 번 돌아갈 것이다.
- bfs를 시작하는 수만 따로 저장하여 출력하면 그것이 답.
- 두 덩어리를 어떻게 이어도 상관 없기 때문이다.
*/

int N;
int x, y;
vector<int> v[300001];
vector<int> st;
int vis[300001];

void bfs(int n)
{
    vis[n] = true;

    for (int i = 0; i < v[n].size(); i++)
    {
        if (!vis[v[n][i]])
            bfs(v[n][i]);
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N;
    
    for (int i = 0; i < N - 2; i++)
    {
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }

    for (int i = 1; i <= N; i++)
    {
        if (!vis[i])
        {
            st.push_back(i); // 새로 bfs를 시작하면 끊어져있다는 뜻
            bfs(i);
        }
    }

    for (int i = 0; i < st.size(); i++) // 아무렇게나 잇기만 하면되므로 st에 있는 수 2개 출력
        cout << st[i] << " ";

    return 0;
}
