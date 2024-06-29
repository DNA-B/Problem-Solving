#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

using namespace std;

/******** MACRO ********/
#define BOUND 100001
#define MOD 1'000'000'007
#define PI 3.1415926535897932
#define ll long long
#define X first
#define Y second
/***********************/

/****** VARIABLEs ******/
int N, split_idx = 0, cnt = 0;
bool is_second = false;
string rhyme;
vector<string> v;
vector<string> team[2];
queue<string> q;
/***********************/


int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	// freopen("input.txt", "r", stdin);

	getline(cin, rhyme);

	for (int i = 0; i < rhyme.size(); i++) {
		if (rhyme[i] == ' ') {
			v.push_back(rhyme.substr(split_idx, i - split_idx));
			split_idx = i + 1;
		}
	}
	v.push_back(rhyme.substr(split_idx, rhyme.size() - split_idx));

	cin >> N;
	cin.ignore();

	for (int i = 0; i < N; i++) {
		string name;
		getline(cin, name);
		q.push(name);
	}

	while (!q.empty()) {
		string cur = q.front();
		q.pop();
		cnt++;

		if (cnt % v.size() == 0) {
			team[is_second].push_back(cur);
			cnt = 0;
			is_second = !is_second;
			continue;
		}
		q.push(cur);
	}

	for (int i = 0; i < 2; i++) {
		cout << team[i].size() << "\n";

		for (auto name : team[i])
			cout << name << "\n";
	}

	return 0;
}