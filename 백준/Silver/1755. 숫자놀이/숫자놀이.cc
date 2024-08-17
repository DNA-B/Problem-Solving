#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

/******** MACRO ********/
#define INT_INF 0x3f3f3f3f
#define LL_INF 1e18
#define MOD 1'000'000'007
#define PI 3.1415926535897932
#define ll long long
#define X first
#define Y second
/***********************/

/****** VARIABLEs ******/
int N, M;
map<string, int> m;
map<char, string> dict = {
	{'0', "zero" }, {'1', "one"}, {'2', "two"}, {'3', "three" },
	{'4', "four"}, {'5', "five"}, {'6', "six" }, {'7', "seven"},
	{'8', "eight"}, {'9', "nine"}
};
/***********************/

int main() {
	cin.tie(NULL)->ios_base::sync_with_stdio(false);
	// freopen("input.txt", "r", stdin);

	cin >> M >> N;

	for (int i = M; i <= N; i++) {
		string tmp = "", ntos = to_string(i);

		for (char ch : ntos)
			tmp += dict[ch] + " ";
		m[tmp] = i;
	}

	int cnt = 0;
	for (auto item : m) {
		cout << item.Y << " ";
		cnt++;

		if (cnt == 10) {
			cnt = 0;
			cout << '\n';
		}
	}

	return 0;
}