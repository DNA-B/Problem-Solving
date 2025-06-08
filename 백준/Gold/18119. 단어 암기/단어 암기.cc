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
int N, M, S;
int mem = (1 << 26) - 1;
vector<int> words;
//=========================//

int get_count() {
	int cnt = 0;
	for (int j = 0; j < N; j++) {
		if ((mem & words[j]) == words[j])
			cnt++;
	}

	return cnt;
}

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG

	cin >> N >> M;

	string s;
	for (int i = 0; i < N; i++) {
		cin >> s;

		int t = 0;
		for (int j = 0; j < s.length(); j++)
			t |= (1 << (s[j] - 'a'));

		words.push_back(t);
	}

	int o;
	char x;
	for (int i = 0; i < M; i++) {
		cin >> o >> x;

		if (o == 1)
			mem &= ~(1 << (x - 'a'));
		else
			mem |= (1 << (x - 'a'));

		cout << get_count() << "\n";
	}
}