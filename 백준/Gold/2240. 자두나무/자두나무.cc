#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#include <unordered_map>
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
int T, W;
int arr[1005];
int mem[35][1005][2];
//=========================//

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG

	cin >> T >> W;

	for (int i = 1; i <= T; i++)
		cin >> arr[i];

	for (int i = 0; i <= W; i++) {
		for (int j = 1; j <= T; j++) {
			if (i == 0) {
				mem[i][j][0] = mem[i][j - 1][0] + (arr[j] == 1);
				continue;
			}

			mem[i][j][0] = max(
				mem[i][j - 1][0] + (arr[j] == 1),
				mem[i - 1][j - 1][1] + (arr[j] == 1));
			mem[i][j][1] = max(
				mem[i][j - 1][1] + (arr[j] == 2),
				mem[i - 1][j - 1][0] + (arr[j] == 2));
		}
	}

	cout << *max_element(mem[W][T], mem[W][T] + 2);
}