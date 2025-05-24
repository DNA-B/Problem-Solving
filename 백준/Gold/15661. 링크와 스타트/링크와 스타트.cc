#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#include <unordered_map>
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
int N, mn = INT_MAX;
vector<int> team1;
int board[25][25];
int vis[25];
//=========================//

int proc(vector<int> team) {
	int score = 0;
	for (int i = 0; i < team.size() - 1; i++) {
		for (int j = i + 1; j < team.size(); j++)
			score += board[team[i]][team[j]] + board[team[j]][team[i]];
	}
	return score;
}

int get_score() {
	vector<int> team2;
	for (int i = 0; i < N; i++)
		if (!vis[i]) team2.push_back(i);
	return abs(proc(team1) - proc(team2));
}

void solve(int idx, int cnt) {
	if (cnt > 0)
		mn = min(mn, get_score());
	if (cnt == N / 2 || idx == N) // 한 팀 구하면 반대편 자동으로 구해짐
		return;

	for (int i = idx; i < N; i++) {
		if (!vis[i]) {
			vis[i] = 1;
			team1.push_back(i);
			solve(i + 1, cnt + 1);
			team1.pop_back();
			vis[i] = 0;
		}
	}
}

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG

	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
			cin >> board[i][j];
	}

	solve(0, 0);
	cout << mn;
}