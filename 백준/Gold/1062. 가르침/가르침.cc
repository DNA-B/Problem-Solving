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
int N, K, mx = -1;
vector<string> words;
int vis[26];
//=========================//

void solve(int idx, int cnt) {
	if (cnt == K - 5) {
		int tmp = 0;
		for (string word : words) {
			bool flag = true;
			for (int i = 0; i < word.size(); i++) {
				if (!vis[word[i] - 'a']) {
					flag = false;
					break;
				}
			}

			if (flag)
				tmp++;
		}

		mx = max(mx, tmp);
		return;
	}

	for (int i = idx; i < 26; i++) {
		if (!vis[i]) {
			vis[i] = 1;
			solve(i + 1, cnt + 1);
			vis[i] = 0;
		}
	}
}

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG

	cin >> N >> K;

	if (K < 5) { // a, c, i, n, t
		cout << 0;
		return 0;
	}

	string tmp, word;
	for (int i = 0; i < N; i++) {
		cin >> tmp;
		word = "";
		for (int j = 4; j < tmp.size() - 4; j++)
			word += tmp[j];
		words.push_back(word);
	}

	vis[0] = vis[2] = vis[8] = vis[13] = vis[19] = 1; // a, c, i, n, t
	solve(1, 0);
	cout << mx;
}