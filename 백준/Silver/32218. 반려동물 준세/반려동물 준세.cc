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
int N;
//=========================//

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG

	cin >> N;

	vector<long long> a(N);
	for (auto& x : a)
		cin >> x;

	int cnt = 0;
	set<vector<long long>> vis;
	while (true) {
		if (vis.count(a)) {
			cout << -1;
			exit(0);
		}

		vis.insert(a);

		vector<long long> b(N, 0);
		for (int i = 0; i < N; i++) {
			for (int j = i + 1; j < N; j++)
				b[i] += (a[j] > a[i]);
		}

		cnt++;

		if (a == b) {
			cout << cnt;
			exit(0);
		}

		a = move(b);
	}
}