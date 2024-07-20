#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

using namespace std;

/******** MACRO ********/
#define BOUND 100001
#define INF 0x3f3f3f3f
#define MOD 1'000'000'007
#define PI 3.1415926535897932
#define ll long long
#define X first
#define Y second
/***********************/

typedef vector<vector<char>> matrix;
/****** VARIABLEs ******/
int N, tc = 1;
int arr[BOUND][3];
ll mem[BOUND][3];
/***********************/


int main() {
	cin.tie(NULL)->ios_base::sync_with_stdio(false);
	// freopen("input.txt", "r", stdin);

	while (1) {
		cin >> N;

		if (N == 0)
			break;

		for (int i = 0; i < N; i++) {
			fill(mem[i], mem[i] + 3, INT_MAX);

			for (int j = 0; j < 3; j++)
				cin >> arr[i][j];
		}

		mem[0][1] = arr[0][1];
		mem[0][2] = arr[0][1] + arr[0][2];

		for (int i = 1; i < N; i++) {
			for (int j = 0; j < 3; j++) {
				if (j == 0)
					mem[i][j] = arr[i][j] + min({ mem[i - 1][0], mem[i - 1][1] });
				else if (j == 1)
					mem[i][j] = arr[i][j] + min({ mem[i][j - 1], mem[i - 1][0], mem[i - 1][1], mem[i - 1][2] });
				else
					mem[i][j] = arr[i][j] + min({ mem[i][j - 1], mem[i - 1][1], mem[i - 1][2] });
			}
		}

		cout << tc++ << ". " << mem[N - 1][1] << "\n";
	}

	return 0;
}