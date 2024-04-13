#define _CRT_SECURE_NO_WARNINGS
#define BOUND 10000
#define first X
#define second Y

#include <bits/stdc++.h>

using namespace std;

string S;
int cnt = 0;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	// freopen("input.txt", "r", stdin);

	cin >> S;

	for (char ch : S) {
		if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
			cnt++;
	}

	cout << cnt;

	return 0;
}