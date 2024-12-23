#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#include <unordered_map>
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
int N, K;
string S;
//=========================//

void flip(int idx) {
	for (int i = idx; i < idx + K; i++)
		S[i] = (S[i] == '+' ? '-' : '+');
}

bool check() {
	for (char ch : S)
		if (ch == '-') return false;
	return true;
}

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
	// freopen("input.txt", "r", stdin);

	cin >> N;

	for (int tc = 1; tc <= N; tc++) {
		cin >> S >> K;

		int cnt = 0;
		for (int i = 0; i <= S.size() - K; i++) {
			if (S[i] == '-') { cnt++; flip(i); }
		}

		cout << "Case #" << tc << ": " << (check() ? to_string(cnt) : "IMPOSSIBLE") << '\n';
	}
}