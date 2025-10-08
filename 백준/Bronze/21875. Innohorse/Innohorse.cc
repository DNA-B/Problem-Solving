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
pair<int, int> a, b;
//=========================//

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG

	cin >> A >> B;
	a = { A[0] - 'a', A[1] - '0' };
	b = { B[0] - 'a', B[1] - '0' };
	int tmp1 = abs(a.X - b.X);
	int tmp2 = abs(a.Y - b.Y);
	cout << min(tmp1, tmp2) << ' ' << max(tmp1, tmp2);
}