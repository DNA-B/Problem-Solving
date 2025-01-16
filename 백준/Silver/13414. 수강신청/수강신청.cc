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
int K, L;
string stu[500005];
map<string, int> m;
//=========================//

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG

	cin >> K >> L;

	for (int i = 0; i < L; i++) {
		cin >> stu[i];
		m[stu[i]] = i;
	}

	for (int cnt = 0, i = 0; (cnt < K && i < L); i++) {
		if (m[stu[i]] == i) {
			cnt++;
			cout << stu[i] << '\n';
		}
	}
}