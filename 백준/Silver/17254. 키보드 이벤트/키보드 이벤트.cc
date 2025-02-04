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
int N, M, a, b;
char c;
vector<tuple<int, int, char>> key;
//=========================//

bool cmp(tuple<int, int, char>& a, tuple<int, int, char>& b) {
	auto [x1, x2, x3] = a;
	auto [y1, y2, y3] = b;

	if (x2 == y2)
		return x1 < y1;

	return x2 < y2;
}

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG

	cin >> N >> M;

	for (int i = 0; i < M; i++) {
		cin >> a >> b >> c;
		key.push_back({ a, b, c });
	}

	sort(key.begin(), key.end(), cmp);

	for (auto [a, b, c] : key)
		cout << c;
}