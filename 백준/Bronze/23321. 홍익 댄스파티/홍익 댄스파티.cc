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
string S[5];
//=========================//

void ready(ll idx) {
	string s2 = "owln.";
	for (ll i = 0; i < 5; i++)
		S[i][idx] = s2[i];
}
void jump(ll idx) {
	string s2 = ".omln";
	for (ll i = 0; i < 5; i++)
		S[i][idx] = s2[i];
}

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG

	for (int i = 0; i < 5; i++)
		cin >> S[i];

	for (int i = 0; i < S[0].length(); i++) {
		if (S[2][i] == 'm')
			ready(i);
		else if (S[2][i] == 'l')
			jump(i);
	}

	for (int i = 0; i < 5; i++)
		cout << S[i] << "\n";
}