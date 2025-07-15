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
int N, cnt = 0;
unordered_map<int, int> um;
//=========================//

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG

	cin >> N;

	int a, b;
	while (N--) {
		cin >> a >> b;
		if (b == 1 && um[a]) // 나온 기록 누락
			cnt++;
		else if (b == 0 && !um[a]) // 들어간 기록 누락
			cnt++;
		um[a] = b;
	}

	for (auto [a, b] : um)
		cnt += um[a]; // 1이면 나온 기록 누락

	cout << cnt;
}