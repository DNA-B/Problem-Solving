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

//=========================//

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG

	int sweet = 0, sour = 0;
	while (cin >> sweet >> sour) {
		if (sweet == 0 && sour == 0)
			exit(0);

		if (sweet + sour == 13)
			cout << "Never speak again.";
		else if (sweet > sour)
			cout << "To the convention.";
		else if (sweet < sour)
			cout << "Left beehind.";
		else
			cout << "Undecided.";
		cout << '\n';
	}
}