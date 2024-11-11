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

	int bound = st;
	while (++bound < en) { // root 노드보다 큰 노드를 발견하면 종료
		if (tree[st] < tree[bound])
			break;
	}

	// postOrder --> [L -> R -> ROOT]
	solve(st + 1, bound); // 루트보다 작은 서브트리 --> L
	solve(bound, en); // 루트보다 큰 서브트라 --> R
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