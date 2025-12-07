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
int K;
string XYZ[3];
map<string, int> m;
//=========================//

void solve(int idx) {
	int len = XYZ[idx].length();
	vector<int> comb(len);

	for (int i = 0; i < K; i++)
		comb[i] = 1;

	do {
		string tmp = "";
		for (int i = 0; i < comb.size(); i++) {
			if (comb[i])
				tmp += XYZ[idx][i];
		}
		m[tmp]++;
	} while (prev_permutation(comb.begin(), comb.end()));
}


int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG

	cin >> XYZ[0] >> XYZ[1] >> XYZ[2] >> K;

	solve(0);
	solve(1);
	solve(2);

	int cnt = 0;
	for (auto [k, v] : m) {
		if (v >= 2) {
			cout << k << '\n';
			cnt++;
		}
	}

	if (!cnt)
		cout << -1;
}