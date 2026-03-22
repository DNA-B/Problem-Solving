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
int N, M;
int arr[100005];
//=========================//

int solve(int x) {
	int cnt = 0, cur = 0;
	for (int i = 0; i < N; i++) {
		if (cur < arr[i]) {
			cnt++;
			cur = 0;
			cur += x;
		}

		if (cur < arr[i]) // 인출을 해도 작으면 x를 키워야 한다.
			return M + 1;

		cur -= arr[i];
	}

	return cnt;
}

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG

	cin >> N >> M;

	for (int i = 0; i < N; i++)
		cin >> arr[i];

	int lo = 0, hi = 1000000000;
	while (lo + 1 < hi) {
		int mid = (lo + hi) / 2;
		int cnt = solve(mid);

		if (cnt <= M) // mid가 너무 커서 인출을 적게 함
			hi = mid;
		else // mid가 너무 작아서 인출을 많이 함
			lo = mid;
	}

	cout << hi;
}