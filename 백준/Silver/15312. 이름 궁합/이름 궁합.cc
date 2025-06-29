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
string A, B;
map<char, char> m = {
	{'A', '3'}, {'B', '2'}, {'C', '1'}, {'D', '2'}, {'E', '3'}, {'F', '3'}, {'G', '2'},
	{'H', '3'}, {'I', '3'}, {'J', '2'}, {'K', '2'}, {'L', '1'}, {'M', '2'}, {'N', '2'},
	{'O', '1'}, {'P', '2'}, {'Q', '2'}, {'R', '2'}, {'S', '1'}, {'T', '2'}, {'U', '1'},
	{'V', '1'}, {'W', '1'}, {'X', '2'}, {'Y', '2'}, {'Z', '1'}
};
//=========================//

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG

	cin >> A >> B;

	string cur = "";
	for (int i = 0; i < A.length(); i++) {
		cur += m[A[i]];
		cur += m[B[i]];
	}

	while (true) {
		string nxt = "";
		for (int i = 0; i < cur.length() - 1; i++) {
			int sum = ((cur[i] - '0') + (cur[i + 1] - '0')) % 10;
			nxt += (sum + '0');
		}

		cur = nxt;
		if (cur.size() == 2) {
			cout << cur;
			exit(0);
		}
	}
}