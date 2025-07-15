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
vector<bool> v(200005);
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
		if (b && v[a]) // 나온 기록 누락
			cnt++;
		else if (!b && !v[a]) // 들어간 기록 누락
			cnt++;
		v[a] = b;
	}


	for (int i = 1; i < v.size(); i++)
		cnt += v[i]; // 1이면 나온 기록 누락

	cout << cnt;
}