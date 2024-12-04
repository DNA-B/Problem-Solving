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
int N, line = 0;
int W[100005];
//=========================//

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
	// freopen("input.txt", "r", stdin);

	cin >> N;

	for (int i = 0; i < N; i++)
		cin >> W[i];

	sort(W, W + N, greater<int>());

	for (int i = 0; i < N; i++) {
		if (line > W[i]) break; // 줄에 대기하고 있는 소보다 W[i]가 작으면 떠남
		line++;
	}
	cout << line;
}