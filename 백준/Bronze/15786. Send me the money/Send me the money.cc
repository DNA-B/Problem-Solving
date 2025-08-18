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
int N, M;
string mem;
string notes[1005];
//=========================//

bool check(string s) {
	int prev = -1, cnt = 0;
	for (int i = 0; i < N; i++) {
		for (int j = prev + 1; j < s.length(); j++) {
			if (s[j] == mem[i]) {
				cnt++;
				prev = j;
				break;
			}
		}
	}

	return cnt == N;
}

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG

	cin >> N >> M >> mem;

	for (int i = 0; i < M; i++)
		cin >> notes[i];

	for (int i = 0; i < M; i++)
		cout << (check(notes[i]) ? "true" : "false") << '\n';
}