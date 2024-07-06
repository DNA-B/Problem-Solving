#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

using namespace std;

/******** MACRO ********/
#define BOUND 101
#define INF 0x3f3f3f3f
#define MOD 1'000'000'007
#define PI 3.1415926535897932
#define ll long long
#define X first
#define Y second
/***********************/

/****** VARIABLEs ******/
int N, M;
int x, y;
vector<int> room(BOUND, 1);
/***********************/

int main() {
	cin.tie(NULL)->ios_base::sync_with_stdio(false);
	// freopen("input.txt", "r", stdin);

	cin >> N >> M;

	while (M--) {
		cin >> x >> y;
		fill(room.begin() + x, room.begin() + y, 0);
	}

	cout << count(room.begin() + 1, room.begin() + (N + 1), 1);
	return 0;
}