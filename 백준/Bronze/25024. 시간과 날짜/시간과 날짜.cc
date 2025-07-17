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
int T, x, y;
vector<int> odd = { 1, 3, 5, 7, 8, 10, 12 };
vector<int> even = { 4, 6, 9, 11 };
//=========================//

bool check_date(int a, int b) {
	if (a < 1 || a > 12) return false;
	if (b < 1 || b > 31) return false;

	if (a == 2) {
		if (b > 29) return false;
		else return true;
	}
	else if (find(even.begin(), even.end(), a) != even.end()) {
		if (b > 30) return false;
		else return true;
	}
	else if (find(odd.begin(), odd.end(), a) != odd.end()) {
		if (b > 31) return false;
		else return true;
	}
}

bool check_time(int a, int b) {
	if (a < 0 || a > 23) return false;
	if (b < 0 || b > 59) return false;
	return true;
}

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG

	cin >> T;

	while (T--) {
		cin >> x >> y;
		if (check_time(x, y))
			cout << "Yes ";
		else
			cout << "No ";

		if (check_date(x, y))
			cout << "Yes\n";
		else
			cout << "No\n";
	}
}