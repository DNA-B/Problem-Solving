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
int H, N;
int res[200005];
vector<pair<int, int>> lights; // { num, r, c };
//=========================//

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG

	cin >> H >> N;
	memset(res, -1, sizeof(res));

	int r, c;
	for (int i = 0; i < N; i++) {
		cin >> r >> c;
		lights.push_back({ c,i });
	}

	sort(lights.begin(), lights.end(), greater<>());

	int move_cnt = N;
	for (auto [c, idx] : lights)
		res[idx] = move_cnt--;

	cout << "YES\n";
	for (int i = 0; i < N; i++)
		cout << res[i] << ' ';
}