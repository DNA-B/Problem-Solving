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
int ori, res = INT_MAX;
string X;
//=========================//

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG

	cin >> X;
	ori = stoi(X);
	sort(X.begin(), X.end());
	do {
		int cur = stoi(X);
		if (cur > ori) res = min(res, cur);
	} while (next_permutation(X.begin(), X.end()));
	cout << (res == INT_MAX ? 0 : res);
}