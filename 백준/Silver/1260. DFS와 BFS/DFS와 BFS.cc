#include <bits/stdc++.h>

using namespace std;

int vu[1001][1001];
int vis_b[1001], vis_d[1001];
queue<int> q;
stack<int> st;
int n, m, v;

void dfs(int v) {
    if (vis_d[v] == 1)
        return;

    cout << v << " ";
    vis_d[v] = 1;

    for (int i = 1; i <= n; i++) {
        if (vu[v][i] == 1 && vis_d[i] == 0)
            dfs(i);
    }
}


void bfs(int s) {
    int nxt = -1;
    q.push(s);

    while (!q.empty()) {
        auto cur = q.front();
        q.pop();

        cout << cur << " ";

        for (int i = 1; i <= n; i++) {
            nxt = vu[cur][i];

            if (vis_b[i] == 0 && nxt == 1) {
                vis_b[i] = 1;
                q.push(i);
            }
        }
    }
}

int main() {
    cin.tie(0)->ios::sync_with_stdio(0);

    cin >> n >> m >> v;
    
    int s, e;
    for (int i = 0; i < m; i++) {
        cin >> s >> e;
        vu[s][e] = vu[e][s] = 1;
    }

    dfs(v);
    cout << "\n";

    vis_b[v] = 1;
    bfs(v);

    return 0;
}