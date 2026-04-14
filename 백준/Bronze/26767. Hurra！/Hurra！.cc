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
int N;
//=========================//

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG

	cin >> N;

	for (int i = 1; i <= N; i++) {
		if (i % 7 == 0 && i % 11 == 0)
			cout << "Wiwat!" << '\n';
		else if (i % 11 == 0)
			cout << "Super!" << '\n';
		else if (i % 7 == 0)
			cout << "Hurra!" << '\n';
		else
			cout << i << '\n';
	}
}