#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#include<unordered_set>
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
int t1, v1, t2, v2;
//=========================//

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG

	cin >> t1 >> v1 >> t2 >> v2;

	if (t2 < 0 && v2 >= 10)
		cout << "A storm warning for tomorrow! Be careful and stay home if possible!";
	else if (t2 - t1 < 0)
		cout << "MCHS warns! Low temperature is expected tomorrow.";
	else if (v2 - v1 > 0)
		cout << "MCHS warns! Strong wind is expected tomorrow.";
	else
		cout << "No message";
}