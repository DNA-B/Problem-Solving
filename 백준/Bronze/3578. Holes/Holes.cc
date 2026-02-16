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
int N;
//=========================//

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG

	cin >> N;

	string tmp = "";

	if (N == 0) {
		cout << 1;
		exit(0);
	}

	if (N == 1) {
		cout << 0;
		exit(0);
	}

	for (int i = 0; i < (N % 2); i++) {
		if (i == 0)
			tmp += '4';
		else
			tmp += '0';
	}

	for (int i = 0; i < (N / 2); i++)
		tmp += '8';

	cout << tmp;
}