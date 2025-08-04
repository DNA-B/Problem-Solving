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
vector<int> v;
//=========================//

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG

	int x;
	while (cin >> x)
		v.push_back(x);

	sort(v.begin(), v.end());

	for (int i = 2; i < v.size(); i++) {
		int a = v[i - 2], b = v[i - 1], c = v[i];
		if (a + b > c) {
			cout << a << ' ' << b << ' ' << c;
			exit(0);
		}
	}

	cout << "NIE";
}