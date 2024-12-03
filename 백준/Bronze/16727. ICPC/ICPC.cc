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
int ph, pa, sh, sa;
//=========================//

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
	// freopen("input.txt", "r", stdin);

	cin >> ph >> sa >> sh >> pa;

	if (ph + pa > sh + sa)
		cout << "Persepolis";
	else if (ph + pa < sh + sa)
		cout << "Esteghlal";
	else {
		if (pa == sa)
			cout << "Penalty";
		else if (pa > sa)
			cout << "Persepolis";
		else
			cout << "Esteghlal";
	}
}