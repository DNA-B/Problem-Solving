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
int M, N;
int rsum[100005], mem[100005];
//=========================//


int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG

	while (cin >> M >> N) {
		if (M == 0 && N == 0)
			break;

		for (int i = 1; i <= M; i++) {
			for (int x, j = 1; j <= N; j++) { // 한 행에서 각 열의 최대 사탕
				cin >> x;
				if (j == 1)
					mem[j] = x;
				else
					mem[j] = max(mem[j - 1], mem[j - 2] + x); // i - 1, i, i + 1의 사탕을 가져가므로, 현재 열(j)를 선택하는 경우 j - 2에서 x를 더한다.
			}
			rsum[i] = mem[N]; // i행에서 가져갈 수 있는 최대 사탕
		}

		for (int j = 1; j <= M; j++) { // 여러 행을 선택할 때의 최대 사탕
			if (j == 1)
				mem[j] = rsum[j];
			else
				mem[j] = max(mem[j - 1], mem[j - 2] + rsum[j]); // 마찬가지로 i - 1, i, i + 1의 사탕을 가져가므로, 현재 행(i)를 선택하는 경우 i - 2에서 rsum을 더한다. 
		}

		cout << mem[M] << '\n';
	}
}