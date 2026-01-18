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
string S;
//=========================//

ll gcd(ll a, ll b) {
	return b ? gcd(b, a % b) : a;
}

void no_cycle() {
	ll ja = stoll(S.substr(2));
	ll mo = pow(10, S.length() - 2);
	ll g = gcd(ja, mo);
	cout << ja / g << "/" << mo / g << '\n';
}

void has_cycle(int st) {
	string tmp1 = S.substr(2, st - 2);
	string tmp2 = S.substr(st + 1);
	tmp2.pop_back(); // ')' 제거
	ll ja = stoll(tmp1 + tmp2);

	if (tmp1 != "")
		ja -= stoll(tmp1);

	ll x1 = pow(10, tmp1.length() + tmp2.length());
	ll x2 = pow(10, st - 2);
	ll mo = abs(x1 - x2);

	ll g = gcd(ja, mo);
	cout << ja / g << '/' << mo / g << '\n';
}

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG

	cin >> T;

	while (T--) {
		cin >> S;
		int st = S.find('(');
		if (st == string::npos)
			no_cycle();
		else
			has_cycle(st);
	}
}