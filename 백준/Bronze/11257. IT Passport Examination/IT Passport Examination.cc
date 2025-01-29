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
int N;
string num;
//=========================//

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG

	cin >> N;

	while (N--) {
		int x1, x2, x3, total = 0, bound = 0;
		cin >> num >> x1 >> x2 >> x3;
		total = x1 + x2 + x3;
		bound = total * 0.3;
		cout << num << ' ' << total << ' ';

		if (total >= 55 && x1 >= 10.5 && x2 >= 7.5 && x3 >= 12)
			cout << "PASS\n";
		else
			cout << "FAIL\n";
	}
}