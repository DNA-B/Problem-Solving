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
int mo, ja, tmp;
string path = "";
//=========================//

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
	// freopen("input.txt", "r", stdin);

	char slash;
	cin >> ja >> slash >> mo;

	while (ja != mo) {
		if (ja > mo) {
			path += 'R';
			tmp = mo;
			mo = ja - mo;
			ja = tmp;
		}
		else if (ja < mo) {
			path += 'L';
			tmp = ja;
			ja = mo - ja;
			mo = tmp;
		}
	}

	cout << path;
	return 0;
}