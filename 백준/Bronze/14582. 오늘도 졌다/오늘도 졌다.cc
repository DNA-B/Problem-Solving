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
int zem[10], gul[10];
//=========================//

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG

	for (int i = 0; i < 9; i++)
		cin >> zem[i];

	for (int i = 0; i < 9; i++)
		cin >> gul[i];

	int total_zem = 0, total_gul = 0;
	for (int i = 0; i < 9; i++) {
		total_zem += zem[i];
		if (total_zem > total_gul) {
			cout << "Yes";
			exit(0);
		}
		total_gul += gul[i];
	}

	cout << "No";
}