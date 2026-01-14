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
int N, M;
int death_or_america[505];
pair<int, int> parents[505];
//=========================//

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG

	cin >> N;

	for (int i = 1; i <= N; i++)
		cin >> parents[i].X >> parents[i].Y;

	cin >> M;

	for (int x, i = 0; i < M; i++) {
		cin >> x;
		death_or_america[x] = 1;
	}

	int cnt = 0;
	for (int i = 1; i <= N; i++) {
		auto [mo, fa] = parents[i];

		if (!mo || !fa) // 어머니와 아버지 중 행방불명이 있으면 X
			continue;
		else if (death_or_america[i] || death_or_america[mo] || death_or_america[fa]) // 부, 모, 자신이 죽거나 미국에 갔으면 X
			continue;

		cnt++;
	}

	cout << cnt;
}