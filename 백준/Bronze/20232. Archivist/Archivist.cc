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
int Y;
vector<string> winner = {
	"ITMO", "SPbSU", "SPbSU", "ITMO", "ITMO",
	"SPbSU", "ITMO", "ITMO", "ITMO", "ITMO",
	"ITMO", "PetrSU, ITMO", "SPbSU", "SPbSU",
	"ITMO", "ITMO", "ITMO", "ITMO", "SPbSU",
	"ITMO", "ITMO", "ITMO", "ITMO", "SPbSU", "ITMO" };
//=========================//

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG

	cin >> Y;
	cout << winner[Y - 1995];
}