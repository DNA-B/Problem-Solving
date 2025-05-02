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
int N, M;
int arr[205];
//=========================//

void rf_shuffle() {
	int tmp[205];
	for (int i = 0; i < N; i++) {
		tmp[2 * i] = arr[i];
		tmp[2 * i + 1] = arr[N + i];
	}

	for (int i = 0; i < 2 * N; i++)
		arr[i] = tmp[i];
}

void k_shuffle(int k) {
	rotate(arr, arr + k, arr + 2 * N);
}

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG

	cin >> N;

	for (int i = 0; i < 2 * N; i++)
		arr[i] = i + 1;

	cin >> M;

	int x;
	while (M--) {
		cin >> x;
		if (!x) rf_shuffle();
		else k_shuffle(x);
	}

	for (int i = 0; i < 2 * N; i++)
		cout << arr[i] << '\n';
}