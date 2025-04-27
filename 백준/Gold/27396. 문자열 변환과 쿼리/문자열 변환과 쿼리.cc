#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#include <unordered_set>
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
string S;
unordered_set<int> idx[65];
//=========================//

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG

	cin >> S >> N;

	for (int i = 0; i < S.length(); i++)
		idx[S[i] - 'A'].insert(i);

	int order;
	while (N--) {
		cin >> order;

		if (order == 1) {
			char from, to;
			cin >> from >> to;

			if (from == to)
				continue;

			for (int id : idx[from - 'A']) {
				idx[to - 'A'].insert(id);
				S[id] = to;
			}

			idx[from - 'A'].clear();
			continue;
		}

		cout << S << '\n';
	}
}