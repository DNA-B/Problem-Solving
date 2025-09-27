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
int T, L, H;
bool is_not_prime[10005];
//=========================//

void era() {
	is_not_prime[1] = true;
	for (int i = 2; i <= sqrt(10000); i++) {
		if (is_not_prime[i])
			continue;
		for (int j = i * i; j <= 10000; j += i)
			is_not_prime[j] = true;
	}
}

bool check(int x) {
	int cnt = ((int)sqrt(x) == sqrt(x));

	for (int i = 1; i < sqrt(x); i++) {
		if (x % i == 0)
			cnt += 2;
	}

	return is_not_prime[cnt] == false;
}

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG

	cin >> T;
	era();

	while (T--) {
		vector<int> p;

		cin >> L >> H;

		for (int i = L; i <= H; i++) {
			if (check(i))
				p.push_back(i);
		}

		if (p.empty()) {
			cout << -1 << '\n';
			continue;
		}

		for (int x : p)
			cout << x << ' ';
		cout << '\n';
	}
}