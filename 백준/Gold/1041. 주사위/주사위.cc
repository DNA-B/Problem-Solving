#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

using namespace std;

/******** MACRO ********/
#define INF 0x3f3f3f3f
#define LLINF 1e18
#define MOD 1'000'000'007
#define PI 3.1415926535897932
#define ll long long
#define X first
#define Y second
/***********************/

/****** VARIABLEs ******/
ll N, res = 0;
int fi, se, th;
int dice[6];
/***********************/

int main() {
	cin.tie(NULL)->ios_base::sync_with_stdio(false);
	// freopen("input.txt", "r", stdin);

	cin >> N;

	for (int i = 0; i < 6; i++)
		cin >> dice[i];

	if (N == 1) {
		sort(dice, dice + 6);
		cout << accumulate(dice, dice + 5, 0LL);
		exit(0);
	}

	fi = se = th = INT_MAX;
	for (int i = 0; i < 6; i++) {
		fi = min(fi, dice[i]);

		for (int j = i + 1; j < 6; j++) {
			if (i + j == 5)
				continue;
			se = min(se, dice[i] + dice[j]);

			for (int k = j + 1; k < 6; k++) {
				if (i + k == 5 || j + k == 5)
					continue;
				th = min(th, dice[i] + dice[j] + dice[k]);
			}
		}
	}

	// 옆면
	res += (N - 1) * (N - 2) * 4 * fi; // 어쩔 수 없는 4개의 옆 면을 뺀 나머지
	res += (N - 1) * 4 * se; // 어쩔 수 없는 4개의 옆 면
	// 윗면
	res += (N - 2) * (N - 2) * fi; // 맨 윗면에서 가장자리를 뺀 가운데 부분
	res += (N - 2) * 4 * se; // 어쩔 수 없는 4개의 옆 면을 뺸 나머지가 가리키는 맨 윗면
	res += 4LL * th; // 어쩔 수 없는 4개의 옆 면이 가리키는 맨 윗면

	cout << res;
	return 0;
}