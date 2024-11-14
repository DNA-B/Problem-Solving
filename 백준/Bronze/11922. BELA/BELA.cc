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
int N, score = 0;
char B, card, suit;
unordered_map<char, int> dominant = {
	{'A', 11}, {'K', 4}, {'Q', 3},
	{'J', 20}, {'T', 10}, {'9', 14},
	{'8', 0}, {'7', 0} };
unordered_map<char, int> not_dominant = {
	{'A', 11}, {'K', 4}, {'Q', 3},
	{'J', 2}, {'T', 10}, {'9', 0},
	{'8', 0}, {'7', 0} };
//=========================//

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
	// freopen("input.txt", "r", stdin);

	cin >> N >> B;

	for (int i = 0; i < 4 * N; i++) {
		cin >> card >> suit;

		if (suit == B)
			score += dominant[card];
		else
			score += not_dominant[card];
	}

	cout << score;
	return 0;
}