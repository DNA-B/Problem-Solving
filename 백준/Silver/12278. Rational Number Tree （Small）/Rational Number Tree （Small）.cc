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
int T, n, x, p, q;
pair<int, int> tree[100005];
//=========================//

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG

	cin >> T;

	int cnt = 0;
	queue<pair<int, int>> tq;


	tq.push({ 1, 1 });
	cnt++;
	tree[cnt] = { 1, 1 };

	while (cnt < pow(2, 16)) {
		auto [p, q] = tq.front(); tq.pop();

		tq.push({ p, p + q });
		cnt++;
		tree[cnt] = { p, p + q };

		tq.push({ p + q, q });
		cnt++;
		tree[cnt] = { p + q, q };
	}

	for (int tc = 1; tc <= T; tc++) {
		cout << "Case #" << tc << ": ";
		cin >> n;

		if (n == 1) {
			cin >> x;
			cout << tree[x].X << " " << tree[x].Y << "\n";
		}
		else if (n == 2) {
			cin >> p >> q;
			for (int i = 0; i < pow(2, 16); i++) {
				if (tree[i].X == p && tree[i].Y == q) {
					cout << i << "\n";
					break;
				}
			}
		}
	}
}