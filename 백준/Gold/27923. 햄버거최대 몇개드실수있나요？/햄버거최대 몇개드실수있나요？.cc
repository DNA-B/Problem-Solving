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
int N, K, L;
int imos[400005];
priority_queue<int> ham, imos_pq;
//=========================//

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG

	cin >> N >> K >> L;

	for (int x, i = 1; i <= N; i++) {
		cin >> x;
		ham.push(x);
	}

	for (int x, i = 0; i < K; i++) {
		cin >> x;
		imos[x]++;
		imos[x + L]--;
	}

	for (int i = 1; i <= N; i++) {
		imos[i] += imos[i - 1];
		imos_pq.push(imos[i]);
	}

	ll m = 0;
	for (int i = 1; i <= N; i++) {
		ll cur_ham = ham.top(); ham.pop();
		ll cur_imos = imos_pq.top(); imos_pq.pop();
		if (cur_imos >= 30) continue;
		m += cur_ham / (1 << cur_imos);
	}

	cout << m;
}