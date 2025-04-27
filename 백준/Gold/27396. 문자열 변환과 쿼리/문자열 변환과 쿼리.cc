#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

//========= MACRO =========//
#define PI 3.1415926535897932
#define INF 0x3f3f3f
#define LL_INF 1e18
#define ll long long
#define X first
#define Y second
//=========================//

//======= VARIABLEs =======//
int N;
string S;
char mapping[65];
//=========================//

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG

	cin >> S >> N;

	for (int i = 0; i < 65; i++)
		mapping[i] = 'A' + i;

	int order;
	while (N--) {
		cin >> order;

		if (order == 1) {
			char from, to;
			cin >> from >> to;

			if (from == to)
				continue;

			for (int i = 0; i < 65; i++) {
				if (mapping[i] == from) {
					mapping[i] = to;
				}
			}
			continue;
		}

		for (char c : S)
			cout << mapping[c - 'A'];
		cout << '\n';
	}
}