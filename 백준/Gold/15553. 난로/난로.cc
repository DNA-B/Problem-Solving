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
int N, K, res = 1;
vector<int> v;
unordered_map<int, int> is_off;
set<pair<int, int>, greater<>> off_idx;
//=========================//

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG

	cin >> N >> K;

	if (K >= N) {
		cout << N;
		return 0;
	}

	for (int x, i = 0; i < N; i++) {
		cin >> x;
		v.push_back(x);
		if (i > 0) off_idx.insert({ x - v[i - 1], v[i - 1] });
	}

	int cnt = 0;
	for (auto [d, x] : off_idx) {
		if (cnt == K - 1) break;
		is_off[x] = true;
		cnt++;
	}

	bool flag = true;
	int pre = v[0];
	for (int i = 0; i < N; i++) {
		if (flag && is_off[v[i]]) {
			res += v[i] - pre;
			flag = false;
		}
		else if (flag && i == N - 1) {
			res += v[i] - pre;
			flag = false;
		}
		else if (!flag && is_off[v[i]]) {
			res++;
			flag = false;
		}
		else if (!flag && !is_off[v[i]]) {
			res++;
			flag = true;
			pre = v[i];
		}
	}

	cout << res;
}