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
int N, M, res = 0;
unordered_map<string, int> um;
//=========================//

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG

	cin >> N >> M;

	int K;
	string sno;
	while (N--) {
		int K;
		string sno;

		cin >> K;
		while (K--) {
			cin >> sno;
			um[sno]++;
		}
	}

	for (auto [sno, cnt] : um) {
		if (cnt >= M)
			res++;
	}

	cout << res;
}