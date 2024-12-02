#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

using namespace std;

int N, M, R, cnt = 1;
int vis[100001];
vector<int> v[100001];
queue<int> q;

int main() {
	cin.tie(0)->ios::sync_with_stdio(0);

	// freopen("input.txt", "r", stdin);

	cin >> N >> M >> R;

	for (int i = 0, st, en; i < M; i++) {
		cin >> st >> en;
		v[st].push_back(en);
		v[en].push_back(st);
	}

	for (int i = 1; i <= N; i++)
		sort(v[i].begin(), v[i].end(), greater<>());

	vis[R] = cnt++;
	q.push(R);

	while (!q.empty()) {
		auto cur = q.front();
		q.pop();

        for (int nxt : v[cur]) {
            if (!vis[nxt]) {
				vis[nxt] = cnt++;
				q.push(nxt);
			}
        }
	}

	for (int i = 1; i <= N; i++)
		cout << vis[i] << "\n";

	return 0;
}