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
int N;
double arr[1000005];
//=========================//

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG

	cout << fixed << setprecision(1);

	int tc = 1;
	while (cin >> N) {
		if (!N) break;

		for (int i = 1; i <= N; i++)
			cin >> arr[i];

		cout << "Case " << tc++ << ": ";

		if (N & 1)
			cout << arr[(N + 1) / 2] << '\n';
		else
			cout << (arr[N / 2] + arr[N / 2 + 1]) / 2.0 << '\n';
	}
}