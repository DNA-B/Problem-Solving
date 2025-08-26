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
string S;
stack<char> ops;
unordered_map<char, int> pri = { {'(', 0}, {')', 1}, {'+', 1}, {'-', 1}, {'*', 2}, {'/', 2} };
//=========================//

void stack_flush(char cur) {
	while (!ops.empty() && pri[cur] <= pri[ops.top()]) {
		cout << ops.top();
		ops.pop();
	}
}

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG

	cin >> S;

	for (int i = 0; i < S.length(); i++) {
		if (S[i] >= 'A' && S[i] <= 'Z') {
			cout << S[i];
			continue;
		}
		else if (S[i] == '(') {
			ops.push(S[i]);
			continue;
		}

		stack_flush(S[i]);

		if (S[i] == ')')
			ops.pop();
		else
			ops.push(S[i]);
	}

	while (!ops.empty()) {
		cout << ops.top();
		ops.pop();
	}
}