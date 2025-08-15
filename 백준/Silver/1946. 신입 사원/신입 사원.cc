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
		int mn_b = INT_MAX;
		vector<pair<int, int>> v;

		cin >> N;

		// 한 쪽 기준으로 정렬한 뒤에 
		// 내 앞에 있는 애들중에 다른 쪽이 더 순위가 높은 얘가 있다면 2개 다 낮은 것

		int a, b;
		for (int i = 0; i < N; i++) {
			cin >> a >> b;
			v.push_back({ a, b });
		}

		sort(v.begin(), v.end());

		int cnt = 0;
		for (auto& [a, b] : v) {
			if (mn_b == INT_MAX || mn_b > b) {
				cnt++;
				mn_b = b;
			}
		}

		cout << cnt << '\n';
	}
}