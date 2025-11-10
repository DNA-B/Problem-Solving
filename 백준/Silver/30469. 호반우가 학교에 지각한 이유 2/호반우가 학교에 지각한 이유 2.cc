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
string A, B;
//=========================//

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG

	cin >> A >> B >> N;

	if ((B[0] - '0') % 2 == 0 || B[0] == '5') {
		cout << -1;
		exit(0);
	}

	if (A[1] == '1' || A[1] == '3' || A[1] == '7')
		A += "1";
	else
		A += "71";

	while (A.length() < N - 2)
		A += "1";

	cout << A + B;
}