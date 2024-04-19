#define _CRT_SECURE_NO_WARNINGS
#define BOUND 101
#define first X
#define second Y

#include <bits/stdc++.h>

using namespace std;

string bowl;
int ans = 0;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	// freopen("input.txt", "r", stdin);

	cin >> bowl;

	char prev = NULL;
	for (char ch : bowl) {
		ans += (ch == prev) ? 5 : 10;
		prev = ch;
	}

	cout << ans;

	return 0;
}