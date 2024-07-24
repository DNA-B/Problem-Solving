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
string board[35][35];
string mem[35][35];
/***********************/

ll to_binary(string tmp) {
	return bitset<65>(tmp).to_ullong();
}

int main() {
	cin.tie(NULL)->ios_base::sync_with_stdio(false);
	// freopen("input.txt", "r", stdin);

	cin >> N;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++)
			cin >> board[i][j];
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			ll tmp = max({ to_binary(mem[i - 1][j] + board[i][j]),to_binary(mem[i][j - 1] + board[i][j]) });
			mem[i][j] = bitset<60>(tmp).to_string();
		}
	}

	cout << bitset<60>(mem[N][N]).to_ullong();
	return 0;
}