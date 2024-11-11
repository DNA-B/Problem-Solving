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
int x;
vector<int> tree;
//=========================//

void solve(int st, int en) {
	if (st >= en)
		return;

	int bound = upper_bound(tree.begin() + (st + 1), tree.begin() + en, tree[st]) - tree.begin(); // 루트보다 큰 값 탐색
	solve(st + 1, bound); // L
	solve(bound, en); // R
	cout << tree[st] << "\n"; // ROOT
}

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
	// freopen("input.txt", "r", stdin);

	while (cin >> x)
		tree.push_back(x);

	solve(0, tree.size());
	return 0;
}