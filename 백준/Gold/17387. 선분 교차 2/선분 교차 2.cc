#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>

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
vector<pair<int, int>> points;
//=========================//

int ccw(pair<ll, ll> a, pair<ll, ll> b, pair<ll, ll> c) {
	ll cp = ((a.X * b.Y) + (b.X * c.Y) + (c.X * a.Y)) - ((a.Y * b.X) + (b.Y * c.X) + (c.Y * a.X));
	if (cp == 0)
		return 0;
	else if (cp < 0)
		return 1;
	else
		return -1;
}

bool solve() {
	int p1p2 = ccw(points[0], points[1], points[2]) * ccw(points[0], points[1], points[3]);
	int p3p4 = ccw(points[2], points[3], points[0]) * ccw(points[2], points[3], points[1]);

	if (p1p2 == 0 && p3p4 == 0) { // 일직선상
		if (points[0] > points[1]) swap(points[0], points[1]); // 좌표값 작은 점이 0번으로
		if (points[2] > points[3]) swap(points[2], points[3]); // 좌표값 작은 점이 2번으로
		return (points[0] <= points[3] && points[2] <= points[1]);
	}

	return (p1p2 <= 0 && p3p4 <= 0);
}

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG

	int x, y;
	for (int i = 0; i < 4; i++) {
		cin >> x >> y;
		points.push_back({ x, y });
	}

	cout << solve();
}