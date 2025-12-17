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
unordered_map<string, int> days = {
   {"Mon", 1}, {"Tue", 2}, {"Wed", 3}, {"Thu", 4},
   {"Fri", 5}, {"Sat", 6}, {"Sun", 7}
};
int T, N;
//=========================//

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG

	cin >> T >> N;

	int total = 0;
	int h1, h2;
	string d1, d2;
	for (int i = 0; i < N; i++) {
		cin >> d1 >> h1 >> d2 >> h2;
		total += 24 * (days[d2] - days[d1]) + (h2 - h1);
	}

	if (T - total > 48)
		cout << -1;
	else if (total >= T)
		cout << 0;
	else
		cout << T - total;
}