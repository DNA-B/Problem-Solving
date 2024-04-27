#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

/******** MACRO ********/
#define BOUND 2001
#define MAX 1'000'000'001
#define ll long long
#define X first
#define Y second
/***********************/

using namespace std;

/****** VARIABLEs ******/
int N;
string tmp;
const set <string> s = { "Never gonna give you up",
					"Never gonna let you down",
					"Never gonna run around and desert you",
					"Never gonna make you cry",
					"Never gonna say goodbye",
					"Never gonna tell a lie and hurt you",
					"Never gonna stop" };
/***********************/

int main() {
	cin.tie(0)->sync_with_stdio(0);

	// freopen("input.txt", "r", stdin);

	cin >> N;
	cin.ignore();

	while (N--) {
		bool flag = true;

		getline(cin, tmp);

		for (auto& promise : s) {
			if (tmp == promise) {
				flag = false;
				break;
			}
		}

		if (flag) { // 하나라도 공약에 속하지 않았다면 Yes 출력 후 종료
			cout << "Yes";
			exit(0);
		}
	}

	cout << "No";

	return 0;
}