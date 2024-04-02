#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

using namespace std;

int P1, P2, P3, X1, X2, X3;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	// freopen("input.txt", "r", stdin);

	cin >> P1 >> P2 >> P3 >> X1 >> X2 >> X3;

	for (int i = 1; i <= P1 * P2 * P3; i++) {
		if ((i % P1 == X1) && (i % P2 == X2) && (i % P3 == X3)) {
			cout << i;
			exit(0);
		}
	}

	cout << -1;

	return 0;
}