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
int T;
//=========================//

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG

	cin >> T;

	for (int tc = 1; tc <= T; tc++) {
		int N, A, B;
		cin >> N >> A >> B;

		cout << "Material Management " << tc << '\n';
		int x, y;
		while (N--)
			cin >> x >> y;
		cout << "Classification ---- End!\n";
	}
}