#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>

using namespace std;

//========= MACRO =========//
#define PI 3.1415926535897932
#define INF 0x3f3f3f3f
#define LL_INF 1e18
#define ll long long
#define X first
#define Y second
//=========================//

//======= VARIABLEs =======//
int N, M;
vector<int> adj[1005];
vector<vector<int>> teams;
//=========================//

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG

	cin >> N >> M;

	int u, v;
	for (int i = 0; i < M; i++) {
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	for (int i = 1; i <= N; i++) {
		bool flag = false;

		for (int j = 0; j < teams.size(); j++) {
			bool can_join = true;

			for (int member : teams[j]) {
				for (int hater : adj[i]) {
					if (member == hater) {
						can_join = false;
						break;
					}
				}

				if (!can_join)
					break;
			}

			if (can_join) {
				teams[j].push_back(i);
				flag = true;
				break;
			}
		}

		if (!flag)
			teams.push_back({ i });
	}

	cout << teams.size() << "\n";
	for (auto team : teams) {
		for (int i = 0; i < team.size(); i++)
			cout << team[i] << (i == team.size() - 1 ? "" : " ");
		cout << "\n";
	}
}