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
int N, rhyme_cnt = 1, loop_cnt = 0;
bool is_second = false;
string rhyme;
vector<string> team[2];
queue<string> q;
/***********************/


int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	// freopen("input.txt", "r", stdin);

	getline(cin, rhyme);

	for (char ch : rhyme) {
		if (ch == ' ')
			rhyme_cnt++;
	}

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
		loop_cnt++;

		if (loop_cnt % rhyme_cnt == 0) {
			team[is_second].push_back(cur);
			loop_cnt = 0;
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