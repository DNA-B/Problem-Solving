#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

using namespace std;

/******** MACRO ********/
#define BOUND 300001
#define INF 0x3f3f3f3f
#define MOD 1'000'000'007
#define PI 3.1415926535897932
#define ll long long
#define X first
#define Y second
/***********************/

/****** VARIABLEs ******/
int A, B, tc = 1;
string op;
/***********************/


int main() {
	cin.tie(NULL)->ios_base::sync_with_stdio(false);
	// freopen("input.txt", "r", stdin);
    
	while (1) {
		cin >> A >> op >> B;

		if (op == "E")
			break;

		if (op == ">")
			cout << "Case " << tc++ << ": " << (A > B ? "true\n" : "false\n");
		else if (op == ">=")
			cout << "Case " << tc++ << ": " << (A >= B ? "true\n" : "false\n");
		else if (op == "<")
			cout << "Case " << tc++ << ": " << (A < B ? "true\n" : "false\n");
		else if (op == "<=")
			cout << "Case " << tc++ << ": " << (A <= B ? "true\n" : "false\n");
		else if (op == "==")
			cout << "Case " << tc++ << ": " << (A == B ? "true\n" : "false\n");
		else if (op == "!=")
			cout << "Case " << tc++ << ": " << (A != B ? "true\n" : "false\n");
	}

	return 0;
}