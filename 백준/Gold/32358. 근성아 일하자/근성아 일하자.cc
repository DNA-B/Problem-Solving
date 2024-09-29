#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

/******** MACRO ********/
#define PI 3.1415926535897932
#define MOD 1000000007
#define INT_INF 0x3f3f3f3f
#define LL_INF 1e18
#define ll long long
#define X first
#define Y second
/***********************/

/****** VARIABLEs ******/
int N, cur = 0;
ll total = 0;
multiset<int> ms;
/***********************/

void remove_trash() {
	while (!ms.empty()) {
		auto tmp2 = ms.lower_bound(cur); // 더 큰 좌표
		auto tmp1 = prev(tmp2); // 더 작은 좌표

		if (tmp2 == ms.end()) {
			total += abs(cur - *tmp1);
			cur = *tmp1;
			ms.erase(tmp1);
		}
		else if (tmp1 == ms.end()) {
			total += abs(cur - *tmp2);
			cur = *tmp2;
			ms.erase(tmp2);
		}
		else if (abs(cur - *tmp1) <= abs(cur - *tmp2)) {
			total += abs(cur - *tmp1);
			cur = *tmp1;
			ms.erase(tmp1);
		}
		else {
			total += abs(cur - *tmp2);
			cur = *tmp2;
			ms.erase(tmp2);
		}
	}
}

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
	// freopen("input.txt", "r", stdin);

	cin >> N;

	int order, x;
	while (N--) {
		cin >> order;

		switch (order) {
			case 1:
				cin >> x;
				ms.insert(x);
				break;
			case 2:
				remove_trash();
				break;
		}
	}

	cout << total;
	return 0;
}