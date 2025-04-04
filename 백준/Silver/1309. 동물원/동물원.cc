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
int mem[100005][2];
//=========================//

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG

	cin >> N;

	mem[1][0] = 1; // 배치 X
	mem[1][1] = 2; // 배치 O

	for (int i = 2; i <= N; i++) {
		mem[i][0] = (mem[i - 1][0] + mem[i - 1][1]) % 9901;
		mem[i][1] = (mem[i - 1][0] * 2 + mem[i - 1][1]) % 9901;
	}

	cout << (mem[N][0] + mem[N][1]) % 9901 << "\n";
}