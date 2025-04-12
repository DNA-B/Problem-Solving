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
int mem_mn[3], mem_mx[3];
//=========================//

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG

	cin >> N;

	int tmp1, tmp2, tmp3;
	for (int a, b, c, i = 0; i < N; i++) {
		cin >> a >> b >> c;

		tmp1 = mem_mn[0];
		tmp2 = mem_mn[1];
		tmp3 = mem_mn[2];

		mem_mn[0] = min(tmp1, tmp2) + a;
		mem_mn[1] = min({ tmp1, tmp2, tmp3 }) + b;
		mem_mn[2] = min(tmp2, tmp3) + c;

		tmp1 = mem_mx[0];
		tmp2 = mem_mx[1];
		tmp3 = mem_mx[2];

		mem_mx[0] = max(tmp1, tmp2) + a;
		mem_mx[1] = max({ tmp1, tmp2, tmp3 }) + b;
		mem_mx[2] = max(tmp2, tmp3) + c;
	}

	cout << *max_element(mem_mx, mem_mx + 3) << " " << *min_element(mem_mn, mem_mn + 3) << "\n";
}