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

//=========================//

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		int stats[3];
		int cnt = 0;

		for (int j = 0; j < 3; j++) {
			cin >> stats[j];
			if (stats[j] >= 10)
				cnt++;
		}

		cout << stats[0] << " " << stats[1] << " " << stats[2] << "\n";

		if (cnt == 0)
			cout << "zilch\n";
		else if (cnt == 1)
			cout << "double\n";
		else if (cnt == 2)
			cout << "double-double\n";
		else if (cnt == 3)
			cout << "triple-double\n";
		cout << "\n";
	}
}