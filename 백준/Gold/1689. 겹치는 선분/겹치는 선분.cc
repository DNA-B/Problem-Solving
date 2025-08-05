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
vector<pair<int, int>> coord;
vector<int> SE;
int imos[2000005];
//=========================//

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG

	cin >> N;

	int s, e;
	for (int i = 0; i < N; i++) {
		cin >> s >> e;
		coord.push_back({ s, e });
		SE.push_back(s);
		SE.push_back(e);
	}

	auto comp = [](vector<int>& tmp) {
		sort(tmp.begin(), tmp.end());
		tmp.erase(unique(tmp.begin(), tmp.end()), tmp.end());
	};

	comp(SE);

	auto trans = [](vector<int>& tmp, int x) {
		return lower_bound(tmp.begin(), tmp.end(), x) - tmp.begin();
	};

	for (auto& [s, e] : coord) {
		int rs = trans(SE, s);
		int re = trans(SE, e);
		imos[rs]++;
		imos[re]--;
	}

	for (int i = 1; i <= 2 * N; i++)
		imos[i] += imos[i - 1];

	cout << *max_element(imos, imos + (2 * N + 1));
}