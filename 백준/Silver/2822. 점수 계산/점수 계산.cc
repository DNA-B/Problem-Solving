#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

#define BOUND 1'000'000'000
#define ll long long
#define X first
#define Y second

using namespace std;

map<int, int, greater<int>> m; // {점수, 문제 번호}
set<int> num;
int total = 0, cnt = 0;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	// freopen("input.txt", "r", stdin);

	for (int score, i = 1; i <= 8; i++) {
		cin >> score;
		m[score] = i;
	}

	for (auto& item : m) {
		total += item.X;
		num.insert(item.Y);
		cnt++;

		if (cnt == 5)
			break;
	}

	cout << total << "\n";

	for (auto& item : num)
		cout << item << " ";

	return 0;
}