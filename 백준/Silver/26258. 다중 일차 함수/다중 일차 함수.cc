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
int N, Q;
double K;
double x[100005], y[100005];
//=========================//

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG

	cin >> N;

	for (int i = 0; i < N; i++)
		cin >> x[i] >> y[i];

	cin >> Q;

	while (Q--) {
		cin >> K;

		int idx = lower_bound(x, x + N, K) - x;
		double inc = (y[idx] - y[idx - 1]) / (x[idx] - x[idx - 1]); // 입력 조건 덕분에 무조건 [1, N-1]로 나옴

		if (x[idx] == K || inc == 0)
			cout << 0 << '\n';
		else
			cout << (inc > 0 ? 1 : -1) << '\n';
	}
}