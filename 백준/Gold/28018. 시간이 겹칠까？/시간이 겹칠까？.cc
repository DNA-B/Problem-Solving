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
int N, Q;
int arr[1000005];
//=========================//

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG

	cin >> N;

	for (int st, en, i = 0; i < N; i++) {
		cin >> st >> en;
		arr[st]++;
		arr[en + 1]--;
	}

	for (int i = 1; i <= 1000000; i++)
		arr[i] += arr[i - 1];

	cin >> Q;

	int q;
	while (Q--) {
		cin >> q;
		cout << arr[q] << '\n';
	}
}