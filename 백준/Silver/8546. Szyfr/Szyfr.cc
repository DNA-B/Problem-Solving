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
//=========================//

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG

	cin >> N >> M;

	int a = 1; // fib(1)
	int b = 1; // fib(2)

	if (N <= 1 && 1 <= M)
		cout << a;
	if (N <= 2 && 2 <= M)
		cout << b;

	for (int i = 3; i <= M; i++) {
		int nxt = (a + b) % 10;
		a = b;
		b = nxt;

		if (i >= N)
			cout << b;
	}
}