#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

using namespace std;

/******** MACRO ********/
#define INF 0x3f3f3f3f
#define LLINF 1e18
#define MOD 1'000'000'007
#define PI 3.1415926535897932
#define ll long long
#define X first
#define Y second
/***********************/

/****** VARIABLEs ******/
string S;
bool U, f_C, P, s_C;
/***********************/

int main() {
	cin.tie(NULL)->ios_base::sync_with_stdio(false);
	// freopen("input.txt", "r", stdin);

	getline(cin, S);

	for (char ch : S) {
		if (U && f_C && P && s_C)
			break;
		else if (U && f_C && P && ch == 'C')
			s_C = true;
		else if (U && f_C && ch == 'P')
			P = true;
		else if (U && ch == 'C')
			f_C = true;
		else if (ch == 'U')
			U = true;
	}

	if (U && f_C && P && s_C)
		cout << "I love UCPC";
	else
		cout << "I hate UCPC";

	return 0;
}