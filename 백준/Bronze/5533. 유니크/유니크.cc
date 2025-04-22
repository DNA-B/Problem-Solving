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
int N;
int arr[205][3], score[205];
//=========================//

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG

	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 3; j++)
			cin >> arr[i][j];
	}

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < N; j++) {
			bool flag = true;
			for (int k = 0; k < N; k++) {
				if (j == k) continue;
				if (arr[j][i] == arr[k][i]) {
					flag = false;
					break;
				}
			}

			if (flag)
				score[j] += arr[j][i];
		}
	}

	for (int i = 0; i < N; i++)
		cout << score[i] << '\n';
}