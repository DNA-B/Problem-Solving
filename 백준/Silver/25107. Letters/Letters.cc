#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

//========= MACRO =========//
#define PI 3.1415926535897932
#define INF 0x3f3f3f3f
#define LL_INF 1e18
#define ll long long
//#define X first
//#define Y second
//=========================//

//======= VARIABLEs =======//
int N, M, K;
char arr[105][105];
string gravity;
//=========================//

void step_U() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (arr[i][j] != '.') {
				for (int k = i; k > 0; k--) {
					if (arr[k - 1][j] == '.')
						swap(arr[k][j], arr[k - 1][j]);
				}
			}
		}
	}
}

void step_D() {
	for (int i = N - 1; i >= 0; i--) {
		for (int j = 0; j < M; j++) {
			if (arr[i][j] != '.') {
				for (int k = i; k < N - 1; k++) {
					if (arr[k + 1][j] == '.')
						swap(arr[k][j], arr[k + 1][j]);
				}
			}
		}
	}
}

void step_L() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (arr[i][j] != '.') {
				for (int k = j; k > 0; k--) {
					if (arr[i][k - 1] == '.')
						swap(arr[i][k], arr[i][k - 1]);
				}
			}
		}
	}
}

void step_R() {
	for (int i = 0; i < N; i++) {
		for (int j = M - 1; j >= 0; j--) {
			if (arr[i][j] != '.') {
				for (int k = j; k < M - 1; k++) {
					if (arr[i][k + 1] == '.')
						swap(arr[i][k], arr[i][k + 1]);
				}
			}
		}
	}
}

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG

	cin >> N >> M >> K;

	cin.ignore();
	getline(cin, gravity);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++)
			cin >> arr[i][j];
	}

	for (char g : gravity) {
		switch (g) {
			case 'U':
				step_U();
				break;
			case 'D':
				step_D();
				break;
			case 'L':
				step_L();
				break;
			case 'R':
				step_R();
				break;
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++)
			cout << arr[i][j];
		cout << '\n';
	}
}