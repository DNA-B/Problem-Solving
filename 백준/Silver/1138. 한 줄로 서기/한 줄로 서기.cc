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
int mem[15];
int line[15], res[15];
//=========================//

bool check() {
	bool flag = true;
	for (int i = 1; i <= N; i++) {
		int cnt = 0;
		for (int j = i - 1; j > 0; j--)
			cnt += (line[i] < line[j]);

		if (cnt != mem[line[i]]) {
			flag = false;
			break;
		}
	}

	return flag;
}

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG

	cin >> N;

	for (int i = 1; i <= N; i++) {
		cin >> mem[i];
		line[i] = i;
	}

	do {
		if (check()) break;
	} while (next_permutation(line + 1, line + (N + 1)));

	for (int i = 1; i <= N; i++)
		cout << line[i] << ' ';
}