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
int num[4];
//=========================//

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG

	cin >> num[0] >> num[1] >> num[2] >> num[3];

	if (num[0] != 8 && num[0] != 9)
		cout << "answer";
	else if (num[3] != 8 && num[3] != 9)
		cout << "answer";
	else if (num[1] != num[2])
		cout << "answer";
	else
		cout << "ignore";
}