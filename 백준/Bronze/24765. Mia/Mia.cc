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
int s0, s1, r0, r1;
//=========================//

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG

	while (true) {
		cin >> s0 >> s1 >> r0 >> r1;

		if (!s0 && !s1 && !r0 && !r1)
			break;

		if (((s0 == 1 && s1 == 2) || (s0 == 2 && s1 == 1)) && ((r0 == 1 && r1 == 2) || (r0 == 2 && r1 == 1)))
			cout << "Tie.\n";
		else if ((s0 == 1 && s1 == 2) || (s0 == 2 && s1 == 1))
			cout << "Player 1 wins.\n";
		else if ((r0 == 1 && r1 == 2) || (r0 == 2 && r1 == 1))
			cout << "Player 2 wins.\n";
		else if (s0 == s1 && r0 != r1)
			cout << "Player 1 wins.\n";
		else if (s0 != s1 && r0 == r1)
			cout << "Player 2 wins.\n";
		else if (s0 == s1 && s1 == r0 && r0 == r1)
			cout << "Tie.\n";
		else if (s0 == s1 && r0 == r1)
			cout << "Player " << (s0 + s1 > r0 + r1 ? 1 : 2) << " wins.\n";
		else {
			string s = to_string(max(s0, s1)) + to_string(min(s0, s1));
			string r = to_string(max(r0, r1)) + to_string(min(r0, r1));
			if (s == r)
				cout << "Tie.\n";
			else
				cout << "Player " << (s > r ? 1 : 2) << " wins.\n";
		}
	}
}