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
int st, en;
int diff[4];
//=========================//

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG

	for (int i = 0; i < 4; i++) {
		cin >> st >> en;
		diff[i] = en - st;
	}

	cout << diff[3] + diff[2] + diff[1] << "\n";
	cout << diff[3] + diff[2] << "\n";
	cout << diff[3] << "\n";
}