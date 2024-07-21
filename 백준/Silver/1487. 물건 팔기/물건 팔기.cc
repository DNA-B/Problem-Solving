#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

using namespace std;

/******** MACRO ********/
#define BOUND 51
#define INF 0x3f3f3f3f
#define LLINF 1e18
#define MOD 1'000'000'007
#define PI 3.1415926535897932
#define ll long long
#define X first
#define Y second
/***********************/

/****** VARIABLEs ******/
int N, res = 0, max_price = 0;
int price, delivery;
pair<int, int> p[BOUND];
/***********************/

int main() {
	cin.tie(NULL)->ios_base::sync_with_stdio(false);
	// freopen("input.txt", "r", stdin);

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> price >> delivery;
		p[i] = { price, delivery };
	}

	sort(p, p + N); // 이익이 최대인 가격이 여러개라면, 가장 낮은 가격을 출력한다.

	for (int i = 0; i < N; i++) {
		int tmp = 0, cur_price = p[i].X;

		for (int j = 0; j < N; j++)
			tmp += (p[j].X >= cur_price && p[i].X > p[j].Y ? cur_price - p[j].Y : 0);

		if (tmp > max_price) {
			max_price = tmp;
			res = cur_price;
		}
	}

	cout << res;
	return 0;
}