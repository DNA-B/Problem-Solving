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
int N, K, total;
vector<int> cards[100];
//=========================//

pair<int, int> solve(int st, int rep) {
	int cur = st;
	while (rep) {
		if (cards[cur].size() >= rep) {
			return { cur, rep - 1 };
		}

		rep -= cards[cur].size();
		cur = (cur + 1) % N;
	}
}

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG

	cin >> N >> K;
	total = N * K;

	for (int i = 0; i < N; i++) {
		int x;
		for (int j = 0; j < K; j++) {
			cin >> x;
			cards[i].push_back(x);
		}
	}

	// 시작은 1번 사람의 맨 왼쪽 카드
	int cur = 0, idx = 0;
	while (total > 1) {
		int rep = cards[cur][idx];
		cards[cur].erase(cards[cur].begin() + idx);
		total--;

		int left = cards[cur].size() - idx;
		if (!cards[cur].empty() && left >= rep)
			idx += rep - 1;
		else
			tie(cur, idx) = solve((cur + 1) % N, rep - left);
	}

	for (int i = 0; i < N; i++) {
		if (!cards[i].empty()) {
			cout << i + 1 << ' ' << cards[i].front();
			exit(0);
		}
	}
}