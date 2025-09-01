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
int A, B, C; // 이벤트, 심신, 사우나
int S, V; // 심신 입장권, 사우나 입장권
int L, E; // 현재 레벨, 필요한 경험치
int res = 0;
//=========================//

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG

	cin >> A >> B >> C >> S >> V >> L;

	E = (250 - L) * 100;

	int sauna = 30 * V * C; // 사우나에서 얻는 경험치
	if (E <= sauna) {
		cout << (E / C) + ((E % C) > 0);
		exit(0);
	}
	else {
		res += 30 * V;
		E -= sauna;
	}

	int simsin = 30 * S * B; // 심신에서 얻는 경험치
	if (E <= simsin) {
		cout << res + (E / B) + ((E % B) > 0);
		exit(0);
	}
	else {
		res += 30 * S;
		E -= simsin;
	}

	cout << res + (E / A) + ((E % A) > 0); // 나머지 이벤트
}