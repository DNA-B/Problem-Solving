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
ll N;
string T;
int vis[30], char_to_idx[128];
char mapping[30];
//=========================//

ll gcd(ll a, ll b) {
	return b == 0 ? a : gcd(b, a % b);
}

ll lcm(ll a, ll b) {
	return a / gcd(a, b) * b;
}

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG

	for (int i = 'A'; i <= 'Z'; ++i)
		char_to_idx[i] = i - 'A';
	char_to_idx['_'] = 26;

	for (int i = 0; i < 27; i++)
		cin >> mapping[i];

	cin >> N >> T;

	ll period = 1;
	for (int i = 0; i < 27; ++i) {
		if (!vis[i]) {
			int idx = i, cycle = 0;

			while (!vis[idx]) {
				vis[idx] = true;
				idx = char_to_idx[mapping[idx]];
				cycle++;
			}

			if (cycle)
				period = lcm(period, cycle);
		}
	}

    N = (N % period != 0 ? N % period : period);

	for (int i = 0; i < N; ++i) {
		for (char& ch : T)
			ch = mapping[char_to_idx[ch]];
	}

	cout << T;
}