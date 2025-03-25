#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#include<unordered_set>
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
int h_lo, h_hi, s_lo, s_hi, v_lo, v_hi;
double R, G, B, M, m;
double V, S, H;
//=========================//

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG

	cin >> h_lo >> h_hi >> s_lo >> s_hi >> v_lo >> v_hi;
	cin >> R >> G >> B;

	M = max({ R, G, B });
	m = min({ R, G, B });

	V = M;
	S = 255 * ((V - m) / V);

	if (V == R)
		H = (60 * (G - B)) / (V - m);
	else if (V == G)
		H = 120 + ((60 * (B - R)) / (V - m));
	else if (V == B)
		H = 240 + ((60 * (R - G)) / (V - m));

	if (H < 0)
		H += 360;

	if ((h_lo <= H && H <= h_hi) && (s_lo <= S && S <= s_hi) && (v_lo <= V && V <= v_hi))
		cout << "Lumi will like it.";
	else
		cout << "Lumi will not like it.";
}