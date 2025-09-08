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
int T, N;
//=========================//

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG

	cin >> T;

	while (T--) {
		char x;
		deque<char> dq;

		cin >> N;

		for (int i = 0; i < N; i++) {
			cin >> x;
			if (dq.empty() || x <= dq.front())
				dq.push_front(x);
			else
				dq.push_back(x);
		}

		for (char ch : dq)
			cout << ch;
		cout << '\n';
	}
}