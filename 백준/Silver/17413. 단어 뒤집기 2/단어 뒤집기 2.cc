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
string S;
//=========================//

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG

	getline(cin, S);

	bool is_open = false;
	int idx = -1;
	for (int i = 0; i < S.size(); i++) {
		if (S[i] == '<') {
			is_open = true;
			continue;
		}
		else if (S[i] == '>') {
			is_open = false;
			continue;
		}
		else if (S[i] != ' ' && !is_open) {
			idx = i + 1;
			while (idx <= S.size()) {
				if (S[idx] == ' ' || S[idx] == '<' || idx == S.size()) {
					reverse(S.begin() + i, S.begin() + idx);
					i = idx - 1;
					break;
				}
				idx++;
			}
		}
	}

	cout << S;
}