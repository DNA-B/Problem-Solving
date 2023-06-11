#include<bits/stdc++.h>
#include<regex>

#define INF 0x3f3f3f3f

using namespace std;

int N, M;
int mem[5001];
int h[5001];
vector<int> shelter[5001];

int dfs(int n)
{
    if (mem[n] != 0)
        return mem[n];

    for (int i = 0; i < shelter[n].size(); i++)
    {
        if (h[n] >= h[shelter[n][i]]) // 자신보다 높이가 낮을 경우 continue
            continue;

        mem[n] = max(mem[n], dfs(shelter[n][i]));
    }

    return ++mem[n];
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;

    for (int i = 1; i <= N; i++)
        cin >> h[i];

    int u, v;
    for (int i = 1; i <= M; i++)
    {
        cin >> u >> v;

        shelter[u].push_back(v); // 높이 조건 추가해서 단방향 가능
        shelter[v].push_back(u); // 일단 양방향으로 진행한 풀이
    }

    for (int i = 1; i <= N; i++)
        cout << dfs(i) << "\n";

    return 0;
}