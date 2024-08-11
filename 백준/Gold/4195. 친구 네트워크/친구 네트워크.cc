#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

/******** MACRO ********/
#define INT_INF 0x3f3f3f3f
#define LL_INF 1e18
#define MOD 1'000'000'007
#define PI 3.1415926535897932
#define ll long long
#define X first
#define Y second
/***********************/

/****** VARIABLEs ******/
int T, N;
vector<int> p;
/***********************/

int uf_find(int x) {
	if (p[x] < 0)
		return x;
	return p[x] = uf_find(p[x]);
}

int uf_union(int a, int b) {
	a = uf_find(a);
	b = uf_find(b);

	if (a == b)
		return p[a];

	if (p[a] <= p[b]) {
		if (p[b] < 0) p[a] += p[b];
		else p[a]--;
		p[b] = a;
	}
	else {
		if (p[a] < 0) p[b] += p[a];
		else p[b]--;
		p[a] = b;
	}

	return min(p[a], p[b]);
}

int main() {
	cin.tie(NULL)->ios_base::sync_with_stdio(false);
	// freopen("input.txt", "r", stdin);

	cin >> T;

	while (T--) {
		p = vector<int>(200005, -1);
		map<string, int> m;
		int idx = 1;
		cin >> N;

		for (int i = 0; i < N; i++) {
			string a, b;
			cin >> a >> b;

			if (m[a] == 0) m[a] = idx++;
			if (m[b] == 0) m[b] = idx++;

			cout << abs(uf_union(m[a], m[b])) << "\n";
		}
	}
    
	return 0;
}