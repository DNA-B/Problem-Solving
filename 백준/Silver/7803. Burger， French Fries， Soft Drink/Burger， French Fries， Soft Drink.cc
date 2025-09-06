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
int mem[35][35];
string order;
//=========================//

void comb() {
	mem[0][0] = 1;
	for (int i = 1; i < 35; i++) {
		mem[i][0] = 1;
		for (int j = 1; j <= i; j++)
			mem[i][j] = mem[i - 1][j - 1] + mem[i - 1][j];
	}
}

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG

	comb();

	while (cin >> N >> order) {
		int B = 0, F = 0, S = 0, cnt = 0;

		for (char& ch : order) {
			if (ch == 'B')
				B++;
			else if (ch == 'F')
				F++;
			else if (ch == 'S')
				S++;

			if (B == F && F == S)
				cnt++;
		}

		if (B != F || F != S) {
			cout << "Impossible\n";
			continue;
		}

		// 문자열 마지막 지점은 분할점으로 사용할 수 없음
		cnt--;

		if (mem[cnt][N - 1])
			cout << mem[cnt][N - 1] << '\n';
		else
			cout << "Impossible\n";
	}
}