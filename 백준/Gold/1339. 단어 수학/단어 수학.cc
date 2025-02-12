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
int N, res = 0;
unordered_map<char, int> um;
vector<int> ranking;
//=========================//

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG

	cin >> N;

	string tmp;
	for (int i = 0; i < N; i++) {
		cin >> tmp;

		int pow = 1;
		for (int j = tmp.size() - 1; j >= 0; j--) {
			um[tmp[j]] += pow;
			pow *= 10;
		}
	}

	for (auto [ch, score] : um)
		ranking.push_back(score);

	sort(ranking.begin(), ranking.end(), greater<>());

	int cnt = 9;
	for (int x : ranking)
		res += x * (cnt--);

	cout << res;
}