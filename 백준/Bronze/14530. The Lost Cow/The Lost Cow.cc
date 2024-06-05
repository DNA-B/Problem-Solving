#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

/******** MACRO ********/
#define BOUND 10
#define MOD 1'000
#define ll long long
#define X first
#define Y second
/***********************/

using namespace std;

/****** VARIABLEs ******/
int x, y;
int cur, nxt, dist = 1, res = 0;
bool flag = false;
/***********************/

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	// freopen("input.txt", "r", stdin);

	cin >> x >> y;
	cur = x;
	nxt = x + dist;

	while (1) {
		while (cur != nxt) { // 현재 위치에서 다음 위치까지 이동
			cur > nxt ? cur-- : cur++;
			res++;

			if (cur == y) { // 중간에 만약 y에 도착한다면 break;
				flag = true;
				break;
			}
		}

		if (flag) {
			cout << res;
			break;
		}

		dist *= -2;
		cur = nxt;
		nxt = x + dist;
	}

	return 0;
}