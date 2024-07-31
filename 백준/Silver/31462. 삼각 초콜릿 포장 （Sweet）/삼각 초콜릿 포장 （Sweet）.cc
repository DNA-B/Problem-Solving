#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

/******** MACRO ********/
#define INF 0x3f3f3f3f
#define LLINF 1e18
#define MOD 1'000'000'007
#define PI 3.1415926535897932
#define ll long long
#define X first
#define Y second
/***********************/

/****** VARIABLEs ******/
int N;
int vis[5001][5001];
char cho[5001][5001];
/***********************/

int main() {
	cin.tie(NULL)->ios_base::sync_with_stdio(false);
	// freopen("input.txt", "r", stdin);

	cin >> N;

	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < i; j++)
			cin >> cho[i][j];
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < i; j++) {
			if (vis[i][j])
				continue;
			if (cho[i][j] == 'R' && vis[i][j] == 0 &&
				cho[i + 1][j] == 'R' && vis[i + 1][j] == 0 &&
				cho[i + 1][j + 1] == 'R' && vis[i + 1][j + 1] == 0)
				vis[i][j] = vis[i + 1][j] = vis[i + 1][j + 1] = 1;
			else if (cho[i][j] == 'B' && vis[i][j] == 0 &&
				cho[i][j + 1] == 'B' && vis[i][j + 1] == 0 &&
				cho[i + 1][j + 1] == 'B' && vis[i + 1][j + 1] == 0)
				vis[i][j] = vis[i][j + 1] = vis[i + 1][j + 1] = 1;
			else {
				cout << 0;
				exit(0);
			}
		}
	}

	cout << 1;
	return 0;
}