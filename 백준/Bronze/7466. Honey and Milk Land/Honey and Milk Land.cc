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
int N, E;
int se = 0, ga = 0;
//=========================//

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG

	cin >> N >> E;

	for (int x, i = 0; i < N - 1; i++) {
		cin >> x;
		se += x;
	}

	for (int x, i = 0; i < E - 1; i++) {
		cin >> x;
		ga += x;
	}

	cout << ceil(hypot(se, ga));
}