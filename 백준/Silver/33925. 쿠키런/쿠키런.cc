#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#include <unordered_set>
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
int N, J, S, H, K;
int obs1 = 0, obs2 = 0, obs3 = 0;
char stage[3][105];
//=========================//

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG

	cin >> N >> J >> S >> H >> K;

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < N; j++)
			cin >> stage[i][j];
	}

	for (int i = 0; i < N; i++) {
		if (stage[0][i] == '.' && stage[1][i] == '^' && stage[2][i] == '^')
			obs2++;
		else if (stage[0][i] == '.' && stage[1][i] == '.' && stage[2][i] == '^')
			obs1++;
		else if (stage[0][i] == 'v' && stage[1][i] == 'v' && stage[2][i] == '.')
			obs3++;
	}

	if (J >= obs1)
		J -= obs1, obs1 = 0;
	else
		obs1 -= max(0, J), J = 0;

	if (J >= 2 * obs2)
		J -= 2 * obs2, obs2 = 0;
	else
		obs2 -= max(0, J / 2), J -= J / 2;

	if (S >= obs3)
		S -= obs3, obs3 = 0;
	else
		obs3 -= max(0, S), S = 0;


	H -= (obs1 * K) + (obs2 * K) + (obs3 * K);
	cout << (H > 0 ? H : -1);
}