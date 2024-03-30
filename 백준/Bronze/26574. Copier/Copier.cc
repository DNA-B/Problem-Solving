#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

using namespace std;

int N;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	// freopen("input.txt", "r", stdin);

	cin >> N;

	for (int x, i = 0; i < N; i++) {
		cin >> x;
		cout << x << " " << x << "\n";
	}

	return 0;
}