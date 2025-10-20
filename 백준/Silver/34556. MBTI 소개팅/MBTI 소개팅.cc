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
int N, mx = -1;
int choices[15], vis[15];
string M[15], F[15];
//=========================//

void solve(int idx) {
	if (idx == N) {
		int score = 0;
		for (int i = 0; i < N; i++) {
			int c = choices[i];
			for (int j = 0; j < 4; j++) {
				if (M[i][j] != F[c][j])
					score++;
			}
		}

		mx = max(mx, score);
		return;
	}

	for (int i = 0; i < N; i++) {
		if (!vis[i]) {
			vis[i] = 1;
			choices[idx] = i;
			solve(idx + 1);
			vis[i] = 0;
		}
	}
}

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG

	cin >> N;

	string mbti;
	for (int i = 0; i < N; i++) {
		cin >> mbti;
		M[i] = mbti;
	}

	for (int i = 0; i < N; i++) {
		cin >> mbti;
		F[i] = mbti;
	}

	solve(0);
	cout << mx;
}