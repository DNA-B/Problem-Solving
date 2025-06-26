#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#include <unordered_set>
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
int N, M, res = 1;
//=========================//

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG

	cin >> N >> M;

	if (N == 0) {
		cout << 0;
		exit(0);
	}

	int cur = 0;
	for (int x, i = 0; i < N; i++) {
		cin >> x;

		if (cur + x > M) {
			res++;
			cur = 0;
		}

		cur += x;
	}

	cout << res;
}