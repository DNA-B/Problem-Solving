#define _CRT_SECURE_NO_WARNINGS
#define BOUND 301
#define first X
#define second Y

#include <bits/stdc++.h>

using namespace std;

int N;
int apple[BOUND][BOUND];
int p_sum[BOUND][BOUND];
int ans = INT_MIN;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	// freopen("input.txt", "r", stdin);

	cin >> N;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> apple[i][j];
			apple[i][j] += apple[i - 1][j] + apple[i][j - 1] - apple[i - 1][j - 1];
		}
	}

	for (int k = 0; k <= N - 1; k++) { // 정사각형 크기
		for (int i = 1; i <= N - k; i++) {
			for (int cur, j = 1; j <= N - k; j++) { // (i, j) ~ (i+k, j+k)의 합
				cur = apple[i + k][j + k] - apple[i + k][j - 1] - apple[i - 1][j + k] + apple[i - 1][j - 1];
				ans = max(ans, cur);
			}
		}
	}

	cout << ans;

	return 0;
}