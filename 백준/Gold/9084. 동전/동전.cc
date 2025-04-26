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
int T, N, M;
int arr[25], mem[10005];
//=========================//

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG

	cin >> T;

	while (T--) {
		cin >> N;
		fill(arr, arr + N, 0);

		for (int i = 0; i < N; i++)
			cin >> arr[i];

		cin >> M;
		fill(mem, mem + (M + 1), 0);

		mem[0] = 1;
		for (int i = 0; i < N; i++)
			for (int j = arr[i]; j <= M; j++)
				mem[j] += mem[j - arr[i]];

		cout << mem[M] << '\n';
	}
}