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
int chk[105], mem[105];
//=========================//

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG

	cin >> N >> M;

	for (int x, i = 0; i < M; i++) {
		cin >> x;
		chk[x] = 1;
	}

	for (int i = 1; i <= N; i++) {
		mem[i] = mem[i - 1] + (chk[i] ? 0 : 7);
		for (int j = 1; j < i; j++)
			mem[i] = min(mem[i], mem[j - 1] + 5 + (2 * (i - j + 1)));
	}

	cout << mem[N];
}