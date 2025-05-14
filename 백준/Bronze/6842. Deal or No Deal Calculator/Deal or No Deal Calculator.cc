#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#include <unordered_set>
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
int N, offer, total = 0;
int dollors[] = { 100, 500, 1000, 5000, 10000, 25000, 50000, 100000, 500000, 1000000 };
//=========================//

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG

	cin >> N;

	total = accumulate(dollors, dollors + 10, 0);

	for (int x, i = 0; i < N; i++) {
		cin >> x;
		total -= dollors[x - 1];
	}

	cin >> offer;

	if (total < offer * (10 - N))
		cout << "deal";
	else
		cout << "no deal";
}