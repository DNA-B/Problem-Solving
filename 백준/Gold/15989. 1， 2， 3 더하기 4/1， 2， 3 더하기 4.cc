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
int T, N;
int mem[10005];
//=========================//

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG

	cin >> T;

	mem[0] = 1; // 공집합
	for (int num : {1, 2, 3}) {
		for (int j = num; j <= 10000; j++)
			mem[j] += mem[j - num];
	}


	while (T--) {
		cin >> N;
		cout << mem[N] << '\n';
	}
}