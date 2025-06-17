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
int d[60][60];
vector<pair<char, char>> v;
//=========================//


int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG

	cin >> N;

	for (int i = 0; i < 60; i++) {
		for (int j = 0; j < 60; j++)
			if (i != j) d[i][j] = INF;
	}

	char st, en;
	string arrow;
	for (int i = 0; i < N; i++) {
		cin >> st >> arrow >> en;
		d[st - 'A'][en - 'A'] = 1;
	}

	for (int k = 0; k < 60; k++) {
		for (int st = 0; st < 60; st++) {
			for (int en = 0; en < 60; en++)
				d[st][en] = min(d[st][en], d[st][k] + d[k][en]);
		}
	}

	for (int st = 0; st < 60; st++) {
		for (int en = 0; en < 60; en++) {
			if (st != en && (d[st][en] != INF && d[st][en] != 0))
				v.push_back({ (char)(st + 'A'), (char)(en + 'A') });
		}
	}

	sort(v.begin(), v.end());

	cout << v.size() << '\n';
	for (auto [st, en] : v)
		cout << st << " => " << en << '\n';
}