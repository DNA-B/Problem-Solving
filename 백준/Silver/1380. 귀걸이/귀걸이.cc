#define _CRT_SECURE_NO_WARNINGS
#define BOUND 101
#define first X
#define second Y

#include <bits/stdc++.h>

using namespace std;

int N, scenario = 1;
int check[BOUND];
map<int, string> m;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	// freopen("input.txt", "r", stdin);

	while (true) {
		cin >> N;
		cin.ignore();

		fill(check + 1, check + (N + 1), 0);
		m = {};

		if (N == 0)
			break;

		for (int i = 1; i <= N; i++) {
			string name;

			getline(cin, name);
			m[i] = name;
		}

		for (int i = 0; i < (2 * N) - 1; i++) { // 귀걸이 돌려받는 작업
			int student_num;
			char a_or_b;

			cin >> student_num >> a_or_b;
			check[student_num]++;
		}

		for (int i = 1; i <= N; i++) {
			if (check[i] != 2) {
				cout << scenario++ << " " << m[i] << "\n";
				break;
			}
		}
	}


	return 0;
}