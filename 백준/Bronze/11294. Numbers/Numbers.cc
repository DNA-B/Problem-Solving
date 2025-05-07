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
string creature;
int basis, decimal;
//=========================//

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG

	while (getline(cin, creature)) {
		if (creature == "#")
			break;

		cin >> basis >> decimal;
		cin.ignore();

		cout << creature << ", " << decimal << ", ";

		stack<int> st;
		while (decimal) {
			st.push(decimal % basis);
			decimal /= basis;
		}

		while (!st.empty()) {
			if (st.top() >= 10) cout << char(st.top() - 10 + 'A');
			else cout << st.top();
			st.pop();
		}
		cout << '\n';
	}
}