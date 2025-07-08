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
int vis[6][6];
char orders[36][2];
//=========================//

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG

	for (int i = 0; i < 36; i++) {
		cin >> orders[i][0] >> orders[i][1];
		int x = orders[i][0] - 'A';
		int y = orders[i][1] - '1';
		vis[x][y] = 1;
	}

	// 나이트가 이동할 수 없는 경로 확인
	for (int i = 1; i < 36; i++) {
		int x1 = orders[i][0] - 'A';
		int y1 = orders[i][1] - '1';
		int x2 = orders[i - 1][0] - 'A';
		int y2 = orders[i - 1][1] - '1';
		if (abs(x1 - x2) == 3 || abs(y1 - y2) == 3 
            || (abs(x1 - x2) + abs(y1 - y2) != 3)) {
			cout << "Invalid";
			exit(0);
		}
	}

	// 모든 칸 방문 했는지 확인
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 6; j++) {
			if (!vis[i][j]) {
				cout << "Invalid";
				exit(0);
			}
		}
	}

	// 마지막 위치에서 처음 위치로 돌아갈 수 있는지 확인
	int x1 = orders[0][0] - 'A';
	int y1 = orders[0][1] - '1';
	int x2 = orders[35][0] - 'A';
	int y2 = orders[35][1] - '1';

	if (abs(x1 - x2) + abs(y1 - y2) != 3)
		cout << "Invalid";
	else
		cout << "Valid";
}