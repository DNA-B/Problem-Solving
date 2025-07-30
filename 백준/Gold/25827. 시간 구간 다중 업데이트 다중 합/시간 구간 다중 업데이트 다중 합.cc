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
const int MAX = 100005;
int N;
ll imos[MAX];
vector<pair<int, int>> queries;
//=========================//

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG

	cin >> N;

	auto get_time = [](string t) {
		int h = stoi(t.substr(0, 2)) * 60 * 60;
		int m = stoi(t.substr(3, 2)) * 60;
		int s = stoi(t.substr(6));
		return h + m + s;
	};

	int order;
	string t1, t2;
	while (N--) {
		cin >> order >> t1 >> t2;
		int st = get_time(t1) + 1; // st가 0이면 누적합 구할 때 인덱스 -1에 접근할 수 있으므로 +1해서 계산
		int en = get_time(t2) + 1;
		if (order == 1) {
			imos[st]++;
			imos[en]--;
		}
		else if (order == 2) {
			queries.push_back({ st, en });
		}
	}

	for (int i = 1; i < MAX; i++) // imos 후처리
		imos[i] += imos[i - 1];

	for (int i = 1; i < MAX; i++) // imos 누적합
		imos[i] += imos[i - 1];

	for (auto& [st, en] : queries)
		cout << imos[en - 1] - imos[st - 1] << '\n';
}