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
int N, KIM, IM;
//=========================//

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG

	cin >> N >> KIM >> IM;

	vector<int> cur, nxt;
	for (int i = 1; i <= N; i++)
		cur.push_back(i);

	int stage = 1;
	while (cur.size() > 1) {
		for (int i = 0; i < cur.size(); i += 2) {
			if (i == cur.size() - 1) {
				nxt.push_back(cur[i]);
				continue;
			}

			int p1 = cur[i];
			int p2 = cur[i + 1];

			if ((p1 == KIM && p2 == IM) || (p1 == IM && p2 == KIM)) {
				cout << stage;
				exit(0);
			}

			if (p1 == KIM || p2 == KIM)
				nxt.push_back(p1 == KIM ? p1 : p2);
			else if (p1 == IM || p2 == IM)
				nxt.push_back(p1 == IM ? p1 : p2);
			else
				nxt.push_back(p1);
		}

		stage++;
		cur = nxt;
		nxt.clear();
	}

	cout << -1;
}