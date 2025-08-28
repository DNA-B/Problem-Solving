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
int N, K;
int arr[105], mem[100005];
//=========================//

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG

	cin >> N >> K;

	for (int i = 0; i < N; i++)
		cin >> arr[i];

	fill(mem, mem + K + 1, INT_MAX);
	mem[0] = 0;

	for (int i = 0; i < N; i++) {
		mem[arr[i]] = 1;
		for (int j = 100000 - arr[i]; j >= 0; j--) {
			if (mem[j] != INT_MAX)
				mem[j + arr[i]] = min(mem[j + arr[i]], mem[j] + 1);
		}
	}

	cout << (mem[K] == INT_MAX ? -1 : mem[K]);
}