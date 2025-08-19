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
int N;
string S;
ll mem[1005];
//=========================//

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG

	cin >> N >> S;
	fill(mem, mem + N, INT_MAX);

	mem[0] = 0;
	for (int i = 1; i < N; i++) {
		for (int j = 0; j < i; j++) {
			int dist = pow(i - j, 2);
			if ((S[i] == 'O' && S[j] == 'B') || (S[i] == 'J' && S[j] == 'O') || (S[i] == 'B' && S[j] == 'J'))
				mem[i] = min(mem[i], mem[j] + dist);
		}
	}

	cout << (mem[N - 1] == INT_MAX ? -1 : mem[N - 1]);
}