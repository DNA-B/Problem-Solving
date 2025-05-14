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
int N, G, cur = 0;
int room[105];
//=========================//

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG

	cin >> N >> G;

	int x;
	bool chk = false;
	while (G--) {
		cin >> x;

		while (x) {
			if (chk) {
				if (room[cur] == 2)
					cur++;
				else
					room[cur++]++, x--;
			}
			else {
				if (x == 1)
					room[cur++] = 1, x--;
				else
					room[cur++] = 2, x -= 2;

				if (cur == N)
					chk = 1, cur = 0;
			}
		}
	}

	for (int i = 0; i < N; i++)
		cout << room[i] << '\n';
}