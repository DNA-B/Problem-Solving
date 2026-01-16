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
const double LE = 0.99, RI = 1.01;
int N, res = 0;
int cakes[10];
vector<int> slt;
//=========================//

ll gcd(int a, int b) {
	return b ? gcd(b, a % b) : a;
}

ll lcm(int a, int b) {
	return a / gcd(a, b) * b;
}

void solve(int idx) {
	if (slt.size() > N)
		return;

	if (slt.size() > 1) {
		ll l = lcm(slt[0], slt[1]);
		for (int i = 2; i < slt.size(); i++)
			l = lcm(l, slt[i]);

		double mo = l, ja = 0;
		for (double x : slt)
			ja += l / x;

		double cri = ja / mo;
		if (LE <= cri && cri <= RI)
			res++;
	}

	for (int i = idx; i < N; i++) {
		slt.push_back(cakes[i]);
		solve(i + 1);
		slt.pop_back();
	}
}

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG

	cin >> N;

	for (int i = 0; i < N; i++)
		cin >> cakes[i];

	solve(0);
	cout << res;
}