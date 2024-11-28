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
unordered_map<char, pair<int, int>> um = {
	{'A', {0, 0}}, {'B', {0, 1}}, {'C', {0, 2}}, {'D', {0, 3}},
	{'E', {1, 0}}, {'F', {1, 1}}, {'G', {1, 2}}, {'H', {1, 3}},
	{'I', {2, 0}}, {'J', {2, 1}}, {'K', {2, 2}}, {'L', {2, 3}},
	{'M', {3, 0}}, {'N', {3, 1}}, {'O', {3, 2}}
};
string puzzle[4];
int dist = 0;
//=========================//


int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
	// freopen("input.txt", "r", stdin);

	for (int i = 0; i < 4; i++)
		cin >> puzzle[i];

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			char cur = puzzle[i][j];
			if (cur != '.')
				dist += abs(um[cur].X - i) + abs(um[cur].Y - j);
		}
	}

	cout << dist;
}