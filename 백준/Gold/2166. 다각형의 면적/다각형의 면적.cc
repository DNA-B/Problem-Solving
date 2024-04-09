#define _CRT_SECURE_NO_WARNINGS
#define X first
#define Y second
#include <bits/stdc++.h>

using namespace std;

int N;
vector<pair<double, double>> p;
double ans = 0.0;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	// freopen("input.txt", "r", stdin);

	cin >> N;

	for (int x, y, i = 0; i < N; i++) {
		cin >> x >> y;
		p.push_back({ x, y });
	}

	for (int i = 1; i < N - 1; i++) { // 삼각형(P0, P1, P2) ~ 삼각형(P0, P(N-2), P(N-1))까지 넓이의 합
		double pa = (p[i].X - p[0].X) * (p[i + 1].Y - p[0].Y);
		double pb = (p[i].Y - p[0].Y) * (p[i + 1].X - p[0].X);
		ans += (pa - pb) / 2;
	}

	cout << fixed;
	cout.precision(1);
	cout << abs(ans); // 시작 방향따라서 음수나올 수도 있음

	return 0;
}