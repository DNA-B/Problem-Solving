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
int N, M, B;
vector<int> res;
vector<tuple<int, set<int>, int>> statements; // (speaker, group, type)
//=========================//

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG

	string dummy;
	getline(cin, dummy); // "swi's cake is missing!"

	cin >> N;

	for (int i = 1; i <= N; ++i) {
		cin >> M;

		int st;
		set<int> S;
		for (int j = 0; j < M; ++j) {
			cin >> st;
			S.insert(st);
		}

		cin >> B;
		statements.push_back({ i, S, B });
	}

	for (int st = 1; st <= N; st++) {
		bool consistent = true;
		for (auto& [s, g, b] : statements) {
			bool cont = g.count(st);
			bool flag;

			if (s == st) // 범인은 거짓말
				flag = !(cont == (b == 1));
			else  // 나머지는 진실
				flag = (cont == (b == 1));

			if (!flag) {
				consistent = false;
				break;
			}
		}

		if (consistent)
			res.push_back(st);
	}

	if (res.empty()) {
		cout << "swi";
		exit(0);
	}

	for (int i = 0; i < res.size(); i++)
		cout << res[i] << ' ';
}