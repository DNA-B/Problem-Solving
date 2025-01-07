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
int N, M;
int arr[100005];
//=========================//

bool check(int x) {
	int total = 0, cnt = 1;
	for (int i = 0; i < N; i++) {
		if (arr[i] > x) return false;
		if (total + arr[i] > x) {
			total = 0;
			cnt++;
		}
		total += arr[i];
	}

	return cnt <= M;
}

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
	// freopen("input.txt", "r", stdin);

	cin >> N >> M;

	for (int i = 0; i < N; i++)
		cin >> arr[i];

	int lo = 0, hi = INF;
	while (lo + 1 < hi) {
		int mid = (lo + hi) / 2;

		if (check(mid))
			hi = mid;
		else
			lo = mid;
	}

	cout << hi;
}