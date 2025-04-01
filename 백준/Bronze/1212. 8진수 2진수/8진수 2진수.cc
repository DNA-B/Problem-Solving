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
string N, b;
//=========================//

string otb(char oct) {
	switch (oct) {
		case '0': return "000";
		case '1': return "001";
		case '2': return "010";
		case '3': return "011";
		case '4': return "100";
		case '5': return "101";
		case '6': return "110";
		case '7': return "111";
		default: return "";
	}
}

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG

	cin >> N;
	for (char ch : N) b += otb(ch);
	b.erase(0, b.find_first_not_of('0'));
	cout << (b.empty() ? "0" : b) << '\n';
}