#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>

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
ll mem[65][10];
//=========================//

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG

	for (int i = 0; i < 10; i++)
		mem[1][i] = 1;

	for (int i = 2; i < 65; i++) { // i번째 자리 수에서 끝나는 수가 j인 경우
		for (int j = 0; j < 10; j++) {
			for (int k = 0; k <= j; k++) // i - 1번째 자리 수에서 j보다 작거나 같은 수를 전부 더한다.
				mem[i][j] += mem[i - 1][k];
		}
	}

	cin >> T;

	while (T--) {
		cin >> N;
		cout << accumulate(mem[N], mem[N] + 10, 0LL) << '\n';
	}
}