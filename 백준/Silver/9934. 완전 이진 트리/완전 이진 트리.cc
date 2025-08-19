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
int K;
int arr[1050];
vector<int> nodes[15];
//=========================//

void solve(int idx, int level) {
	if (level == K + 1)
		return;

	int nxt = pow(2, K - (level + 1));

	solve(idx - nxt, level + 1);
	nodes[level].push_back(arr[idx]);
	solve(idx + nxt, level + 1);
}

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG

	cin >> K;

	for (int i = 0; i < pow(2, K) - 1; i++)
		cin >> arr[i];

	int st = (pow(2, K) - 1) / 2;
	solve(st, 1);

	for (int i = 1; i <= K; i++) {
		for (int node : nodes[i])
			cout << node << ' ';
		cout << '\n';
	}
}