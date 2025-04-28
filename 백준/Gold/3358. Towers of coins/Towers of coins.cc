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
int K, L, M;
bool mem[1000005];
//=========================//

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG

	cin >> K >> L >> M;

	mem[0] = 0;
	for (int i = 1; i <= 1000000; i++) {
		bool x = 0;
		x = x || !mem[i - 1];
		if (i >= K) x = x || !mem[i - K];
		if (i >= L) x = x || !mem[i - L];
		mem[i] = x;
	}

	for (int i = 0; i < M; i++) {
		cin >> K;
		cout << (mem[K] ? "A" : "B");
	}
}