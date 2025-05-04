#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#include <unordered_set>
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
int N, mx = -1;
vector<int> adj[100005];
//=========================//

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG

	cin >> N;

	for (int st, en, i = 0; i < N - 1; i++) {
		cin >> st >> en;
		adj[st].push_back(en);
		adj[en].push_back(st);
	}

	for (int i = 1; i <= N; i++)
		mx = max(mx, (int)adj[i].size());

	cout << mx + 1;
}