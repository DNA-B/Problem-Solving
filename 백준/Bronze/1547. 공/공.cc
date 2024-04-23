#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

#define BOUND 1'000'000'000
#define ll long long
#define first X
#define second Y

using namespace std;

int M;
map<int, int> m;
int ball = 1; // 1번 컵 위치에 공 존재

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	// freopen("input.txt", "r", stdin);

	cin >> M;

	for (int i = 1; i <= 3; i++)
		m[i] = i;

	while (M--) {
		int x, y;

		cin >> x >> y;
		swap(m[x], m[y]);
	}

	for (int i = 1; i <= 3; i++) {
		if (m[i] == ball) {
			cout << i;
			break;
		}
	}

	return 0;
}