#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#include <unordered_map>
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
int T;
double N;
string U;
map<string, double> unit_conversion = { {"kg", 2.2046}, {"lb", 0.4536}, {"l", 0.2642}, {"g", 3.7854} };
map<string, string> conversion_name = { {"kg", "lb"}, {"lb", "kg"}, {"l", "g"}, {"g", "l"} };
//=========================//

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG

	cin >> T;

	cout << fixed << setprecision(4);
	while (T--) {
		cin >> N >> U;
		cout << N * unit_conversion[U] << ' ' << conversion_name[U] << '\n';
	}
}