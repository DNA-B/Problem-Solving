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
int N, a, b;
int mem[1000005];
//=========================//

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
	// freopen("input.txt", "r", stdin);

	cin >> N >> a >> b;

	for (int i = 1; i <= N; i++) {
		mem[i] = mem[i - 1] + 1; // 기다리기
		if (i - a - 1 >= 0)
			mem[i] = min(mem[i], mem[i - a - 1] + 1); // a만큼 새치기
		if (i - b - 1 >= 0)
			mem[i] = min(mem[i], mem[i - b - 1] + 1); // b만큼 새치기
	}

	cout << mem[N];
}