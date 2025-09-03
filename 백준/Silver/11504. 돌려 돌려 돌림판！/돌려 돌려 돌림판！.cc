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
int T;
//=========================//

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG

	cin >> T;

	while (T--) {
		int N, M;
		string X = "", Y = "";

		cin >> N >> M;

		int ch;
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < M; j++) {
				cin >> ch;
				if (i == 0) X += ch + '0';
				else Y += ch + '0';
			}
		}

		int wheel[105];
		for (int i = 0; i < N; i++)
			cin >> wheel[i];

		int cnt = 0;
		for (int i = 0; i < N; i++) {
			if (X[0] - '0' <= wheel[i] && wheel[i] <= Y[0] - '0') {
				string Z = "";
				for (int j = i; j < i + M; j++)
					Z += wheel[j % N] + '0';

				if (X <= Z && Z <= Y)
					cnt++;
			}
		}

		cout << cnt << '\n';
	}
};