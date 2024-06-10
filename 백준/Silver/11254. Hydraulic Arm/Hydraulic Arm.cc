#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

/******** MACRO ********/
#define BOUND 10001
#define MOD 1'000'000'007
#define ll long long
#define X first
#define Y second
/***********************/

using namespace std;

/****** VARIABLEs ******/
int T, N, cnt;
stack<int> shelf;
/***********************/

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	// freopen("input.txt", "r", stdin);

	cin >> T;

	while (T--) {
		cnt = 1;
		shelf = {};

		cin >> N;

		for (int a, i = 0; i < N; i++) {
			cin >> a;

			if (a == cnt)
				cnt++;
			else if (shelf.empty() || a < shelf.top())
				shelf.push(a);

			while (!shelf.empty() && shelf.top() == cnt) { // 선반에 있는 계란판을 옮길 수 있다면 옮긴다.
				cnt++;
				shelf.pop();
			}
		}

		cout << (cnt - 1 == N ? "yes\n" : "no\n");
	}

	return 0;
}