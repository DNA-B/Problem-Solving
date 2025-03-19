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
int S, A, B;
//=========================//

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG

	cin >> S >> A >> B;

	int div = (S - A) / B;
	int mod = (S - A) % B;
	int price = 250;

	if (div > 0) price += div * 100;
	if (S - A > 0 && mod != 0) price += 100;
	cout << price;
}