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
int N, K, cnt = 0;
vector<int> v;
//=========================//

void solve(int total) {
	if (total > N)
		return;
	if (total == N) {
		cnt++;
		if (cnt == K) {
			for (int i = 0; i < v.size() - 1; i++)
				cout << v[i] << '+';
			cout << v.back();
			exit(0);
		}
	}

	for (int num : {1, 2, 3}) {
		v.push_back(num);
		solve(total + num);
		v.pop_back();
	}
}

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG

	cin >> N >> K;
	solve(0);
	cout << -1;
}