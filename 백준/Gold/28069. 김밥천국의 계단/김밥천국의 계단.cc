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
int vis[1000005];
queue<int> q;
//=========================//

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG

	cin >> N >> K;

	vis[0] = 1;
	q.push(0);
	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		if (cur + 1 <= 1000000 && !vis[cur + 1]) {
			vis[cur + 1] = vis[cur] + 1;
			q.push(cur + 1);
		}

		if (cur + (cur / 2) <= 1000000 && !vis[cur + (cur / 2)]) {
			vis[cur + (cur / 2)] = vis[cur] + 1;
			q.push(cur + (cur / 2));
		}
	}

	cout << (vis[N] - 1 <= K ? "minigimbob" : "water");
}