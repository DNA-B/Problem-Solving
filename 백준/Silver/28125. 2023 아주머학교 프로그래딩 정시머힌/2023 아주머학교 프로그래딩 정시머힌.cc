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
//=========================//

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG

	cin >> N;

	while (N--) {
		int cnt = 0;
		string S, res = "";

		cin >> S;

		for (int i = 0; i < S.length(); i++) {
			if (i <= S.length() - 3 && S.substr(i, 3) == R"(\\')") {
				res += "w";
				i += 2;
				cnt++;
			}
			else if (i <= S.length() - 2 && (S.substr(i, 2) == R"(\')")) {
				res += "v";
				i += 1;
				cnt++;
			}
			else if (S[i] == '7') {
				res += 't';
				cnt++;
			}
			else if (S[i] == '0') {
				res += 'o';
				cnt++;
			}
			else if (S[i] == '^') {
				res += 'n';
				cnt++;
			}
			else if (S[i] == ';') {
				res += 'j';
				cnt++;
			}
			else if (S[i] == '!') {
				res += 'i';
				cnt++;
			}
			else if (S[i] == '[') {
				res += 'c';
				cnt++;
			}
			else if (S[i] == '@') {
				res += 'a';
				cnt++;
			}
			else
				res += S[i];
		}

		if (2 * cnt >= res.length())
			cout << "I don't understand\n";
		else
			cout << res << '\n';
	}
}