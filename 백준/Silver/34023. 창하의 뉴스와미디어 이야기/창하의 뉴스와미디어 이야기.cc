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
int N;
vector<pair<int, string>> problems;
set<string> classes[200005];
//=========================//

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG

	cin >> N;

	string s;
	int d;
	for (int i = 0; i < N; i++) {
		cin >> s >> d;
		problems.push_back({ d, s });
	}

	sort(problems.begin(), problems.end());

	for (int i = 0; i < N; i++) {
		auto [d, s] = problems[i];
		classes[i % 4].insert(s);
	}

	for (int i = 0; i < 4; i++) {
		cout << i + 1;
		for (string p : classes[i])
			cout << " " << p;
		cout << '\n';
	}
}