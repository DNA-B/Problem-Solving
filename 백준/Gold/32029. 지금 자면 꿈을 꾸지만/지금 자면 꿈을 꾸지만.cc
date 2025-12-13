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
int N, A, B, mx = 0;
int T[105];
//=========================//

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG

	cin >> N >> A >> B;

	for (int i = 0; i < N; i++)
		cin >> T[i];

	sort(T, T + N);

	for (int x = 0; x < A; x++) {
		for (int i = 0; i < N; i++) {
			int cur = 0, cnt = 0;
			for (int j = 0; j < N; j++) {
				if (j == i)
					cur += B * x;

				int tmp = cur + (j < i ? A : A - x);
				if (tmp <= T[j]) {
					cur = tmp;
					cnt++;
				}
			}
			mx = max(mx, cnt);
		}
	}

	cout << mx;
}