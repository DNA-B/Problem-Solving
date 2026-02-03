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
int A, B, C, D;
int P, M, N;
//=========================//

int solve(int t) {
	int cnt = 0;

	int remain1 = t % (A + B);
	if (remain1 <= A && remain1 != 0)
		cnt++;

	int remain2 = t % (C + D);
	if (remain2 <= C && remain2 != 0)
		cnt++;

	return cnt;
}

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG
    
	cin >> A >> B >> C >> D;
	cin >> P >> M >> N;
	cout << solve(P) << '\n' << solve(M) << '\n' << solve(N);
}