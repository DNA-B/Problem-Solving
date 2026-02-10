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
int A, B, cnt = 0;
//=========================//

void solve(string cur) {
	ll tmp = stoll(cur);

	if (tmp > B)
		return;
	if (tmp >= A)
		cnt++;

	solve(cur + '4');
	solve(cur + '7');
}

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG

	cin >> A >> B;
	solve("4");
	solve("7");
	cout << cnt;
}