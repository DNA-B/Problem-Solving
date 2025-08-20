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
int T;
double C, F, X;
//=========================//

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG

	cout << fixed << setprecision(7);
	cin >> T;

	for (int tc = 1; tc <= T; tc++) {
		cin >> C >> F >> X;

		double rate = 2.0;
		double t = 0.0;

		while ((C / rate) + (X / (rate + F)) < (X / rate)) { // 공장 설립 O < 공장 설립 X
			t += C / rate; // 공장 설립까지 걸리는 시간
			rate += F; // 속도 증가
		}

		t += X / rate;
		cout << "Case #" << tc << ": " << t << "\n";
	}
}