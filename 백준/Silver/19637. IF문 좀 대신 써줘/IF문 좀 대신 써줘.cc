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
vector<int> v;
multimap<int, string> dict;
//=========================//

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG

	cin >> N >> M;

	int bound;
	string style;
	for (int i = 0; i < N; i++) {
		cin >> style >> bound;
		v.push_back(bound);
		dict.insert({ bound, style });
	}

	sort(v.begin(), v.end(), greater<>());

	int power;
	for (int i = 0; i < M; i++) {
		cin >> power;
		auto it = upper_bound(v.begin(), v.end(), power, greater<>());
		cout << dict.find(*(--it))->Y << '\n';
	}
}