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
int cnt = 0;
int vis[2505];
string sound;
string QUACK = "quack";
//=========================//

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG

	cin >> sound;

	int idx = 0;
	for (int i = 0; i < sound.length() - QUACK.length(); i++) {
		if (!vis[i]) {
			for (int j = i; j < sound.length(); j++) {
				if (!vis[j] && sound[j] == QUACK[idx]) {
					vis[j] = 1;
					idx++;
					if (idx >= QUACK.length())
						idx = 0;
				}
			}

			if (idx == 0) {
				cnt++;
			}
			else {
				cout << -1;
				exit(0);
			}
		}
	}

	if (count(vis, vis + sound.length(), 0) > 0) {
		cout << -1;
		exit(0);
	}

	cout << (cnt == 0 ? -1 : cnt);
}