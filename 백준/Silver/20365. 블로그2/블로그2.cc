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
string S, mn;
//=========================//

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG

	cin >> N >> S;
	for (char ch : S) {
		if (mn.empty() || mn.back() != ch)
			mn += ch;
	}

	int B = 0, R = 0;
	for (char ch : mn) {
		if (ch == 'B') B++;
		else R++;
	}

	cout << min(B, R) + 1;
}