#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;
//========= MACRO =========//
#define PI 3.1415926535897932
#define INT_INF 0x3f3f3f3f
#define LL_INF 1e18
#define ll long long
#define X first
#define Y second
//=========================//

//======= VARIABLEs =======//
int T, N;
//=========================//

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	// freopen("input.txt", "r", stdin);

	cin >> T;

	for (int tc = 1; tc <= T; tc++) {
		cin >> N;
		cout << "Case #" << tc << ": ";

		if (N <= 25)
			cout << "World Finals\n";
		else if (N <= 1000)
			cout << "Round 3\n";
		else if (N <= 4500)
			cout << "Round 2\n";
		else
			cout << "Round 1\n";
	}
	return 0;
}