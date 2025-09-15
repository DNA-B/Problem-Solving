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
int C, N;
int mem[2005];
vector<pair<int, int>> cities;
//=========================//

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG

	cin >> C >> N;

	int cost, customer;
	for (int i = 0; i < N; i++) {
		cin >> cost >> customer;
		cities.push_back({ cost, customer });
	}

	fill(mem, mem + 2005, INF);
	mem[0] = 0;

	for (auto [cost, customer] : cities)
		for (int i = customer; i <= 2000; i++)
			mem[i] = min(mem[i], mem[i - customer] + cost);

	int res = INT_MAX;
	for (int i = C; i <= 2000; i++)
		res = min(res, mem[i]);

	cout << res << "\n";
}