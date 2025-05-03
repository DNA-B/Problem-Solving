#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#include <unordered_set>
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
int T, C, P;
//=========================//

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG

	cin >> T;

	while (T--) {
		unordered_map<string, tuple<int, int, int>> um;
		string name, csize, cname;
		int small, medium, large;
		int dprice;

		cin >> C >> P;

		dprice = 100 / P;

		for (int i = 0; i < C; i++) {
			cin >> cname >> small >> medium >> large;
			um[cname] = { small, medium, large };
		}

		for (int i = 0; i < P; i++) {
			int price = dprice;
			cin >> name >> csize >> cname;

			if (csize == "small")
				price += get<0>(um[cname]);
			else if (csize == "medium")
				price += get<1>(um[cname]);
			else if (csize == "large")
				price += get<2>(um[cname]);

			if (price % 5 == 4)
				price += 1;
			else if (price % 5 == 1)
				price -= 1;

			cout << name << " " << price << '\n';
		}
	}
}