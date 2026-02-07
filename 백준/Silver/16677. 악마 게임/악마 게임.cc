#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>

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
string M;
vector<pair<string, int>> words;
//=========================//

bool check(string w) {
	int idx = 0;
	for (char ch : w) {
		if (ch == M[idx])
			idx++;
		if (idx == M.length())
			return true;
	}

	return false;
}

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG

	cin >> M >> N;

	string w;
	int g;
	for (int i = 0; i < N; i++) {
		cin >> w >> g;
		words.push_back({ w, g });
	}

	string res;
	double mx = -1;
	for (auto [w, g] : words) {
		if (w.length() >= M.length() && check(w)) {
			double val = 1.0 * g / (w.length() - M.length());
			if (mx < val) {
				mx = val;
				res = w;
			}
		}
	}

	cout << (mx == -1 ? "No Jam" : res);
}