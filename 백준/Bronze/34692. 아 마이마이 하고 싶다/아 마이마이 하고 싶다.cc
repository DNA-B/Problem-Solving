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
int N, M, K;
int machines[1005];
//=========================//

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG

	cin >> N >> M >> K;

	int t;
	for (int i = 0; i < N; i++) {
		cin >> t;
		int mn = *min_element(machines, machines + M);
		for (int j = 0; j < M; j++) {
			if (machines[j] == mn) {
				machines[j] += t;
				break;
			}
		}
	}

	if (*min_element(machines, machines + M) > K)
		cout << "GO";
	else
		cout << "WAIT";
}