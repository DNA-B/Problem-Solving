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
ll N, U, D;
ll A[1000005], B[1000005];
ll diff_A[1000005], diff_B[1000005], sum_A[1000005], sum_B[1000005];
//=========================//

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG

	cin >> N >> U >> D;

	for (int i = 1; i <= N; ++i)
		cin >> A[i];
	for (int i = 1; i <= N; ++i)
		cin >> B[i];

	for (int i = 1; i <= N; ++i) {
		ll K = B[i] - A[i];

		if (K < 0) {
			diff_B[i] += 1;
			diff_B[N + 1] -= 1;
			ll val_B = B[i] + (D * i);
			sum_B[i] += val_B;
			sum_B[N + 1] -= val_B;
		} else {
			ll maxT = N - i;
			ll T = K / (U + D);

			if (T > maxT)
				T = maxT;

			diff_A[i] += 1;
			diff_A[i + T + 1] -= 1;
			ll val_A = A[i] - (U * i);
			sum_A[i] += val_A;
			sum_A[i + T + 1] -= val_A;

			if (i + T < N) {
				diff_B[i + T + 1] += 1;
				diff_B[N + 1] -= 1;
				ll val_B = B[i] + (D * i);
				sum_B[i + T + 1] += val_B;
				sum_B[N + 1] -= val_B;
			}
		}
	}

	ll cnt_A = 0, cnt_B = 0;
	ll total_A = 0, total_B = 0;
	for (int n = 1; n <= N; ++n) {
		cnt_A += diff_A[n];
		cnt_B += diff_B[n];
		total_A += sum_A[n];
		total_B += sum_B[n];
		cout << (U * n * cnt_A) - (D * n * cnt_B) + total_A + total_B << '\n';
	}
}