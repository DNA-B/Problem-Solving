#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;
//========= MACRO =========//
#define PI 3.1415926535897932
#define INT_INF 0x3f3f3f3f
#define LL_INF 1e18
#define ll long long
#define X first
#define Y second
//=========================//

//======= VARIABLEs =======//
int T, K;
int psum[505], arr[505], mem[505][505];
//=========================//

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
	// freopen("input.txt", "r", stdin);

	cin >> T;

	while (T--) {
		cin >> K;

		for (int i = 1; i <= K; i++) {
			cin >> arr[i];
			psum[i] = psum[i - 1] + arr[i];
		}

		for (int i = 1; i <= K; i++) { // 파일을 합칠 개수
			for (int j = 1; j <= K - i; j++) { // 시작점
				mem[j][i + j] = INT_INF;
				for (int k = j; k < i + j; k++) // 구분점
					mem[j][i + j] = min(mem[j][i + j], mem[j][k] + mem[k + 1][i + j] + psum[i + j] - psum[j - 1]);
			}
		}
		cout << mem[1][K] << '\n';
	}

	return 0;
}