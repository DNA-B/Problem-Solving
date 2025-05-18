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
int N;
int comb[1005][5];
int mx_score[1005];
//=========================//

void get_mx(int cur) {
	int k = 3, mx = -1;
	int tmp[] = { 0, 0, 1, 1, 1 };

	do {
		int score = 0;
		for (int i = 0; i < 5; i++)
			if (tmp[i]) score += comb[cur][i];
		mx = max(mx, score % 10); // 3개의 수를 더해도 100이 넘지 않음
	} while (next_permutation(tmp, tmp + 5));

	mx_score[cur] = mx;
}

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG

	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 5; j++)
			cin >> comb[i][j];
		get_mx(i);
	}

	int mx = -1, idx = -1;
	for (int i = 0; i < N; i++) {
		if (mx <= mx_score[i]) {
			mx = mx_score[i];
			idx = i;
		}
	}

	cout << idx + 1;
}