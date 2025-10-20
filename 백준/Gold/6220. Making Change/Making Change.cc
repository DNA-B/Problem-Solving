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
int C, N;
int coins[15], mem[1005];
//=========================//

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG

	cin >> C >> N;

	for (int i = 0; i < N; i++)
		cin >> coins[i];

	fill(mem, mem + 1005, INF);

	mem[0] = 0;
	for (int i = 0; i < N; i++)
		for (int j = coins[i]; j <= C; j++)
			mem[j] = min(mem[j], mem[j - coins[i]] + 1);

	cout << mem[C];
}