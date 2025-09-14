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
struct Comp {
	int X, W, F, C;
};

int L, N, B;
int mem[1005][1005]; // { pos, cost }
vector<Comp> comps[1005];
//=========================//

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG

	cin >> L >> N >> B;

	int x, w, f, c;
	for (int i = 0; i < N; i++) {
		cin >> x >> w >> f >> c;
		comps[x].push_back({ x, w, f, c });
	}

	memset(mem, -1, sizeof(mem));
	mem[0][0] = 0;

	for (int pos = 0; pos <= L; pos++) {
		for (int cost = 0; cost <= B; cost++) {
			if (mem[pos][cost] == -1)
				continue;

			for (auto& [x, w, f, c] : comps[pos]) {
				int nxt = x + w;
				int nxt_cost = cost + c;
				if (nxt <= L && nxt_cost <= B)
					mem[nxt][nxt_cost] = max(mem[nxt][nxt_cost], mem[pos][cost] + f);
			}
		}
	}

	int res = -1;
	for (int c = 0; c <= B; c++)
		res = max(res, mem[L][c]);

	cout << res;
}