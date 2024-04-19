#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

#define BOUND 1001
#define ll long long
#define first X
#define second Y

using namespace std;

ll N;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	// freopen("input.txt", "r", stdin);

	cin >> N;

	ll sq_n = sqrt(N);

	if ((sq_n * sq_n) < N)
		sq_n++;

	cout << sq_n;

	return 0;
}