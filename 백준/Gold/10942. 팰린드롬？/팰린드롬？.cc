#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

using namespace std;

int N, M, st, en;
int arr[2001];
int mem[2001][2001];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	// freopen("input.txt", "r", stdin);

	cin >> N;

	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
		mem[i][i] = true; // 스스로는 팰린드롬 수
	}

	for (int i = 1; i <= N - 1; i++) { // 길이가 2
		if (arr[i] == arr[i + 1])
			mem[i][i + 1] = true;
	}

	for (int i = N - 2; i >= 1; i--) { // 길이가 3 이상
		for (int j = i + 2; j <= N; j++) {
			if (arr[i] == arr[j] && mem[i + 1][j - 1]) {
				mem[i][j] = true;
			}
		}
	}

	cin >> M;

	while (M--) {
		cin >> st >> en;
		cout << mem[st][en] << "\n";
	}

	return 0;
}