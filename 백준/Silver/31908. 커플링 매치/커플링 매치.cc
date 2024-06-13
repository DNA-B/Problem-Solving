#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

/******** MACRO ********/
#define BOUND 10001
#define MOD 1'000'000'007
#define ll long long
#define X first
#define Y second
/***********************/

using namespace std;

/****** VARIABLEs ******/
int N, cnt = 0;
vector<vector<string>> couple_list;
map<string, vector<string>> m;
/***********************/

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	// freopen("input.txt", "r", stdin);

	cin >> N;

	while (N--) {
		string name, ring;

		cin >> name >> ring;
        
        if (ring == "-")
			continue;
        
		m[ring].push_back(name);
	}

	cnt = count_if(m.begin(), m.end(), [](pair<string, vector<string>> item) {
		return item.second.size() == 2;
		});

	cout << cnt << "\n";

	for (auto item : m) {
		if (item.second.size() == 2) {
			for (string couple : item.second)
				cout << couple << " ";
			cout << "\n";
		}
	}

	return 0;
}