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
int N;
int outdegree[105];
//=========================//

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG

	cin >> N;

	int u, v;
	for (int i = 0; i < N; i++) {
		cin >> u >> v;
		outdegree[u]++;
	}

	int cnt = count(outdegree + 1, outdegree + (N + 1), 0);

	if (cnt != 1) {
		cout << -1;
		exit(0);
	}

	cout << find(outdegree + 1, outdegree + (N + 1), 0) - outdegree;
}