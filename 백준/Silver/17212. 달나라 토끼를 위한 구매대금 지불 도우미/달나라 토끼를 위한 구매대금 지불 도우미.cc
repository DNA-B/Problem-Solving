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
int N;
int coins[] = { 7, 5, 2, 1 };
int mem[100005];
//=========================//

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG

	cin >> N;
	fill(mem, mem + (N + 1), INF);

	mem[0] = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 4; j++) {
			if (i + coins[j] <= N)
				mem[i + coins[j]] = min(mem[i + coins[j]], mem[i] + 1);
		}
	}

	cout << mem[N];
}