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
int L, T;
//=========================//

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG

	string vote;
	for (int i = 0; i < 9; i++) {
		cin >> vote;
		if (vote == "Lion") L++;
		else T++;
	}

	cout << (L > T ? "Lion" : "Tiger");
}