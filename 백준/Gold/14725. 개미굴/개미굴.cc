#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

/******** MACRO ********/
#define PI 3.1415926535897932
#define MOD 1000000007
#define INT_INF 0x3f3f3f3f
#define LL_INF 1e18
#define ll long long
#define ull usnsigned long long
#define X first
#define Y second
/***********************/

/****** VARIABLEs ******/
const int ROOT = 1;
const int BOUND = 1000 * 15 + 5;
int N, M;
int unused = 2;
map<string, int> nxt[BOUND];
/***********************/

void insert(vector<string>& v) {
	int cur = ROOT;
	for (auto& s : v) {
		if (!nxt[cur][s])
			nxt[cur][s] = unused++;
		cur = nxt[cur][s];
	}
}

void dfs(int cur, int depth) {
	for (auto food : nxt[cur]) {
		string output;
		for (int i = 0; i < depth; i++)
			output += "--";
		cout << output << food.X << '\n';
		dfs(food.Y, depth + 1);
	}
}

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
	// freopen("input.txt", "r", stdin);

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> M;
		vector<string> foods(M);
		for (string& food : foods)
			cin >> food;
		insert(foods);
	}

	dfs(ROOT, 0);
	return 0;
}