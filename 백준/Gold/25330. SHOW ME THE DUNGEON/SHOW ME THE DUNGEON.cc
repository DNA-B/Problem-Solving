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
int N, K, mx = 0;
bool chk[25];
pair<int, int>town[25];
//=========================//

void solve(int cur, int damage, int save) {
	if (save > mx)
		mx = save;
	if (cur == 0)
		return;

	int remain = 0;
	for (int i = 0; i < N; i++) {
		auto [attack, people] = town[i];
		if (!chk[i] && damage + attack <= cur)
			remain += people;
	}

	if (save + remain <= mx) // 현재 체력으로 갈 수 있는 모든 마을의 생존자를 합쳐도 최대보다 작으면 return;
		return;

	for (int i = 0; i < N; i++) {
		auto [attack, people] = town[i];
		if (!chk[i] && damage + attack <= cur) {
			chk[i] = true;
			solve(cur - (damage + attack), damage + attack, save + people);
			chk[i] = false;
		}
	}
}

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
	// freopen("input.txt", "r", stdin);

	cin >> N >> K;

	for (int i = 0; i < N; i++) cin >> town[i].X;
	for (int i = 0; i < N; i++) cin >> town[i].Y;

	solve(K, 0, 0);
	cout << mx;
}