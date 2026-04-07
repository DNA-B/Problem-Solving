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

	for (int i = 0; i < N; i++) {
		bool has17 = false;
		bool has18 = false;

		int x;
		for (int j = 0; j < 10; j++) {
			cin >> x;
			if (j > 0) cout << " ";
			cout << x;

			if (x == 17)
				has17 = true;
			if (x == 18)
				has18 = true;
		}
		cout << '\n';

		if (has17 && has18)
			cout << "both" << '\n';
		else if (has17)
			cout << "zack" << '\n';
		else if (has18)
			cout << "mack" << '\n';
		else
			cout << "none" << '\n';
		cout << '\n';
	}
}