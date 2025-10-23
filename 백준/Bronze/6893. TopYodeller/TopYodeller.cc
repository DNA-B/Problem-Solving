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
int N, K;
int yodellers[105], worst_rank[105];
//=========================//

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG

	cin >> N >> K;
	fill(worst_rank, worst_rank + N, INT_MIN);

	while (K--) {
		vector<pair<int, int>> tmp;

		for (int x, i = 0; i < N; i++) {
			cin >> x;
			yodellers[i] += x;
			tmp.push_back({ yodellers[i], i });
		}

		sort(tmp.begin(), tmp.end(), greater<>()); // 점수 내림차순 정렬

		int rank = 1;
		for (int i = 0; i < tmp.size(); i++) {
			auto [score, idx] = tmp[i];

			if (i > 0 && tmp[i].X != tmp[i - 1].X)
				rank++;

			worst_rank[idx] = max(worst_rank[idx], rank);
		}
	}

	int max_yodel_score = *max_element(yodellers, yodellers + N);
	int idx = 0;
	while (true) {
		idx = find(yodellers + idx, yodellers + N, max_yodel_score) - yodellers;
		if (idx == N)
			break;
		else
			cout << "Yodeller " << idx + 1 << " is the TopYodeller: score " << max_yodel_score << ", worst rank " << worst_rank[idx] << '\n';
		idx++;
	}
}