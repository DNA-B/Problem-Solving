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
int N, M;
vector<pair<int, string>> v;
//=========================//

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG

	cin >> N >> M;

	int bound;
	string style;
	for (int i = 0; i < N; i++) {
		cin >> style >> bound;
		v.push_back({ bound ,style });
	}

	int power;
	for (int i = 0; i < M; i++) {
		cin >> power;

		int lo = 0, hi = N;
		while (lo + 1 < hi) {
			int mid = (lo + hi) / 2;

			if (power <= v[mid].X)
				hi = mid;
			else
				lo = mid;
		}

		if (power > v[lo].X)
			cout << v[lo + 1].Y << '\n';
		else
			cout << v[lo].Y << '\n';
	}
}