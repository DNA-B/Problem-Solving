#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
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
int T, N, K, Tid, M;
//=========================//

bool cmp(tuple<int, int, int, int>& a, tuple<int, int, int, int>& b) {
	auto [score1, sub_cnt1, last_sub1, team_a] = a;
	auto [score2, sub_cnt2, last_sub2, team_b] = b;

	if (score1 == score2 && sub_cnt1 == sub_cnt2)
		return last_sub1 < last_sub2;
	else if (score1 == score2)
		return sub_cnt1 < sub_cnt2;
	else
		return score1 > score2;
}

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG

	cin >> T;

	while (T--) {
		int sub[105][105];
		int score[105] = { 0 };
		int sub_cnt[105] = { 0 };
		int last_sub[105] = { 0 };
		vector<tuple<int, int, int, int>> team; // { score, sub_cnt, last_sub, team_id }

		cin >> N >> K >> Tid >> M; // 팀, 문제, 내 팀 id, 로그 엔트리

		for (int i = 1; i <= N; i++)
			for (int j = 1; j <= K; j++)
				sub[i][j] = 0;

		int i, j, s; // 팀 id, 문제 번호, 점수
		for (int x = 0; x < M; x++) {
			cin >> i >> j >> s;

			if (sub[i][j] < s) {
				score[i] -= sub[i][j];
				sub[i][j] = s;
				score[i] += s;
			}

			sub_cnt[i]++;
			last_sub[i] = x;
		}

		for (int i = 1; i <= N; i++)
			team.push_back({ score[i], sub_cnt[i], last_sub[i], i });

		sort(team.begin(), team.end(), cmp);

		for (int i = 0; i < team.size(); i++) {
			auto [score, sub_cnt, last_sub, team_id] = team[i];

			if (team_id == Tid) {
				cout << i + 1 << '\n';
				break;
			}
		}
	}
}