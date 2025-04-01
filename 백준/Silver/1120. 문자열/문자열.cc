#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
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
string A, B;
int mn = INT_MAX;
//=========================//

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG

	cin >> A >> B;

	for (int i = 0; i <= B.size() - A.size(); i++) {
		int cnt = 0;
		for (int j = 0; j < A.size(); j++)
			if (A[j] != B[j + i]) cnt++;
		mn = min(mn, cnt);
	}

	cout << mn << '\n';
}