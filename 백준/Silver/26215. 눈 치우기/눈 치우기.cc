#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

//========= MACRO =========//
#define PI 3.1415926535897932
#define INF 0x3f3f3f3f
#define LL_INF 1e18
#define ll long long
#define X first
#define Y second
//=========================//

//======= VARIABLEs =======//
int N, cnt = 0;
priority_queue<int> pq;
//=========================//

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG

	cin >> N;

	for (int x, i = 0; i < N; i++) {
		cin >> x;
		pq.push(x);
	}

	while (!pq.empty()) {
		if (pq.size() > 1) {
			int a = pq.top(); pq.pop();
			int b = pq.top(); pq.pop();
			if (a - 1 > 0)  pq.push(--a);
			if (b - 1 > 0) pq.push(--b);
			cnt++;
		}
		else {
			int a = pq.top(); pq.pop();
			if (a - 1 > 0) pq.push(--a);
			cnt++;
		}
	}

	cout << (cnt > 1440 ? -1 : cnt);
}