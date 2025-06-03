#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#include <unordered_map>
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
const int MAX = 10000000;
int K;
vector<bool> is_not_prime(MAX + 5);
//=========================//

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG

	cin >> K;

	for (int i = 2; i <= sqrt(MAX); i++) {
		if (is_not_prime[i]) continue;
		for (int j = i * i; j <= MAX; j += i)
			is_not_prime[j] = true;
	}

	int cnt = 0;
	for (int i = 2; i <= MAX; i++) {
		if (!is_not_prime[i]) {
			cnt++;
			if (cnt == K) {
				cout << i;
				exit(0);
			}
		}
	}
}