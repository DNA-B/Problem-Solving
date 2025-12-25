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

	int N;
	while (T--) {
		cin >> N;

		int total = 0;
		char x;
		for (int i = 0; i < 2 * N + 1; i++) {
			cin >> x;
			if (i % 2 == 0) {
				if (x == '!')
					total += 10;
				else
					total += (x - '0');
			}
		}

		if (total > 9)
			cout << '!' << '\n';
		else
			cout << total << '\n';
	}
}