#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

/******** MACRO ********/
#define BOUND 10001
#define MAX 1'000'000'001
#define MOD 10000
#define ll long long
#define X first
#define Y second
/***********************/

using namespace std;

/****** VARIABLEs ******/
int T, A, B;
/***********************/

int order_D(int n) {
	return (n * 2) % MOD;
}

int order_S(int n) {
	return (n == 0 ? 9999 : n - 1);
}

int order_L(int n) {
	string tmp = to_string(n);

	while (tmp.size() < 4) // 문자열이 4자리가 아니면 앞에 '0' 채워주기
		tmp.insert(tmp.begin(), '0');

	rotate(tmp.begin(), tmp.begin() + 1, tmp.end());

	return stoi(tmp);
}

int order_R(int n) {
	string tmp = to_string(n);

	while (tmp.size() < 4) // 문자열이 4자리가 아니면 앞에 '0' 채워주기
		tmp.insert(tmp.begin(), '0');

	rotate(tmp.begin(), tmp.end() - 1, tmp.end());

	return stoi(tmp);
}

int main() {
	cin.tie(0)->sync_with_stdio(0);

	// freopen("input.txt", "r", stdin);

	cin >> T;

	while (T--) {
		vector<int> vis(BOUND, -1);
		vector<char> order(BOUND); // 경로 찾는 용도
		queue<int> q;
		bool flag = false;

		cin >> A >> B;

		q.push(A);
		vis[A] = INT_MAX;

		while (!q.empty()) {
			int cur = q.front();
			q.pop();

			for (int dir = 0; dir < 4; dir++) {
				int nx;
				char nx_path;

				switch (dir) {
					case 0:
						nx = order_D(cur);
						nx_path = 'D';
						break;
					case 1:
						nx = order_S(cur);
						nx_path = 'S';
						break;
					case 2:
						nx = order_L(cur);
						nx_path = 'L';
						break;
					case 3:
						nx = order_R(cur);
						nx_path = 'R';
						break;
				}

				if (vis[nx] != -1)
					continue;

				vis[nx] = cur;
				order[nx] = nx_path;
				q.push(nx);

				if (nx == B) { // 도착
					flag = true;
					break;
				}
			}

			if (flag) // 도착 시 break
				break;
		}

		string path;
		int cur_path = B;

		while (true) {
			if (cur_path == A)
				break;

			path += order[cur_path];
			cur_path = vis[cur_path];
		}

		reverse(path.begin(), path.end());
		cout << path << "\n";
	}

	return 0;
}