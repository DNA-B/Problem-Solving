#include <bits/stdc++.h>

using namespace std;

int N, M, L;
vector<int> party[51];
vector<int> graph[51];
int parent[51];
int ans = 0;

int getParent(int x)
{
    if (parent[x] == x)
        return x;

    return parent[x] = getParent(parent[x]);
}

void unionParent(int a, int b)
{
    a = getParent(a);
    b = getParent(b);

    parent[max(a, b)] = min(a, b);
}

void makeGraph(int n)
{
    for (int i = 0; i < party[n].size() - 1; i++)
    {
        graph[party[n][i]].push_back(party[n][i + 1]);
        graph[party[n][i + 1]].push_back(party[n][i]);
    }
}

void dfs(int n)
{
    for (int i = 0; i < graph[n].size(); i++)
    {
        if (parent[graph[n][i]] == 0)
            continue;

        unionParent(n, graph[n][i]);
        dfs(graph[n][i]);
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M >> L;

    for (int i = 0; i <= N; i++)
        parent[i] = i;

    for (int i = 0; i < L; i++)
    {
        int x;

        cin >> x;
        unionParent(0, x);
    }

    for (int i = 0; i < M; i++)
    {
        int n, people;
        bool founded = false;

        cin >> n;

        for (int j = 0; j < n; j++)
        {
            cin >> people;
            party[i].push_back(people);
        }

        makeGraph(i);
    }

    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < party[i].size(); j++)
        {
            if (parent[party[i][j]] == 0)
                dfs(party[i][j]);
        }
    }

    for (int i = 0; i < M; i++)
    {
        bool founded = false;

        for (int j = 0; j < party[i].size(); j++)
        {
            if (parent[party[i][j]] == 0)
            {
                founded = true;
                break;
            }
        }

        if (!founded)
            ans++;
    }

    cout << ans;

    return 0;
}