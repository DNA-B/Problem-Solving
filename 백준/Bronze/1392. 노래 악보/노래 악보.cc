#define _CRT_SECURE_NO_WARNINGS
#define BOUND 10001
#define first X
#define second Y

#include <bits/stdc++.h>

using namespace std;

int N, Q;
int cur_music[BOUND];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	// freopen("input.txt", "r", stdin);

	cin >> N >> Q;

	int music, cnt = 0;
	for (int i = 1; i <= N; i++) {
		cin >> music;

		for (int j = 0; j < music; j++)
			cur_music[cnt++] = i;
	}

	int question;
	while (Q--) {
		cin >> question;
		cout << cur_music[question] << "\n";
	}

	return 0;
}