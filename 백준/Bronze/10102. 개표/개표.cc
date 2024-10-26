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
int V, A = 0, B = 0;
string vote;
//=========================//

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
	// freopen("input.txt", "r", stdin);

	cin >> V >> vote;

	for (char& ch : vote)
		(ch == 'A' ? A++ : B++);

	if (A > B)
		cout << 'A';
	else if (A < B)
		cout << 'B';
	else
		cout << "Tie";

	return 0;
}