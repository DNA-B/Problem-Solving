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
string sf;
//=========================//

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG

	while (cin >> sf) {
		if (sf == "TTYL")
			break;

		if (sf == "CU")
			cout << "see you\n";
		else if (sf == ":-)")
			cout << "I’m happy\n";
		else if (sf == ":-(")
			cout << "I’m unhappy\n";
		else if (sf == ";-)")
			cout << "wink\n";
		else if (sf == ":-P")
			cout << "stick out my tongue\n";
		else if (sf == "(~.~)")
			cout << "sleepy\n";
		else if (sf == "TA")
			cout << "totally awesome\n";
		else if (sf == "CCC")
			cout << "Canadian Computing Competition\n";
		else if (sf == "CUZ")
			cout << "because\n";
		else if (sf == "TY")
			cout << "thank-you\n";
		else if (sf == "YW")
			cout << "you’re welcome\n";
		else
			cout << sf << '\n';
	}
	cout << "talk to you later";
}