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
double fr[3], ba[7];
vector<tuple<double, int, int>> comb;
//=========================//

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG

	for (int i = 0; i < 3; i++)
		cin >> fr[i];

	for (int i = 0; i < 7; i++)
		cin >> ba[i];

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 7; j++)
			comb.push_back({ fr[i] / ba[j], i + 1, j + 1 });
	}

	sort(comb.begin(), comb.end());

	cout << fixed << setprecision(2);
	for (auto [v, f, b] : comb)
		cout << v << ' ' << f << ' ' << b << '\n';
}