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
string s;
/***********************/

int main() {
	cin.tie(NULL)->ios_base::sync_with_stdio(false);
	// freopen("input.txt", "r", stdin);

	cin >> s;

	for (int i = 0; i < s.size(); i++) {
		if (s[i] == 'p' && s.substr(i, 2) == "pi")
			i += 1;
		else if (s[i] == 'k' && s.substr(i, 2) == "ka")
			i += 1;
		else if (s[i] == 'c' && s.substr(i, 3) == "chu")
			i += 2;
		else {
			cout << "NO";
			exit(0);
		}
	}

	cout << "YES";
	return 0;
}