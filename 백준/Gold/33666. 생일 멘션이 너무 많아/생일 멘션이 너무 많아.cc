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
int N, M;
int imos[1000005];
ll mentions[1000005];
//=========================//

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG

	cin >> N >> M;

	int cnt = 0;
	ll total = 0, am = 0;
	for (int i = 1; i <= N; i++) {
		cin >> mentions[i];
		if (mentions[i] >= 2) {
			total += mentions[i];
			cnt++;
		}
	}

	am = (cnt == 0) ? 0 : total / cnt;

    if (am > M) {
        cout << -1;
        exit(0);
    }
    
	for (int i = 1; i <= N; i++) {
		if (mentions[i] <= am) {
			imos[1]++;
			imos[mentions[i] + 1]--;
		}
		else {
			imos[1]++;
			imos[2]--;
		}
	}

	for (int i = 1; i <= M; i++) {
		imos[i] += imos[i - 1];
		cout << imos[i] << ' ';
	}
}