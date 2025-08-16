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
ll T, N;
ll mem[50]; // 45번째 피보나치수가 1,134,903,170
//=========================//

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG

	mem[0] = 0, mem[1] = 1;
	int mx = 0;
	for (int i = 2; i <= 50; i++) {
		mem[i] = mem[i - 1] + mem[i - 2];
		if (mem[i] >= 1000000000) {
			mx = i;
			break;
		}
	}

	cin >> T;
	while (T--) {
		stack<ll> st;

		cin >> N;
		for (int i = mx; i >= 0; i--) {
			if (mem[i] <= N) {
				N -= mem[i];
				st.push(mem[i]);
			}

			if (N == 0)
				break;
		}

		while (!st.empty()) {
			cout << st.top() << (st.size() == 1 ? '\n' : ' ');
			st.pop();
		}
	}
}