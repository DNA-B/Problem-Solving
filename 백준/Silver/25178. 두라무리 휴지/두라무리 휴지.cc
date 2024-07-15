#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

using namespace std;

/******** MACRO ********/
#define BOUND 201
#define INF 0x3f3f3f3f
#define MOD 1'000'000'007
#define PI 3.1415926535897932
#define ll long long
#define X first
#define Y second
/***********************/

/****** VARIABLEs ******/
int N;
string s1, s2;
/***********************/

void test1(string tmp1, string tmp2) {
	sort(tmp1.begin(), tmp1.end());
	sort(tmp2.begin(), tmp2.end());

	if (tmp1 != tmp2) {
		cout << "NO";
		exit(0);
	}
}

void test2(string tmp1, string tmp2) {
	if ((tmp1[0] != tmp2[0]) || tmp1[tmp1.size() - 1] != tmp2[tmp2.size() - 1]) {
		cout << "NO";
		exit(0);
	}
}

void test3(string tmp1, string tmp2) {
	string removed_tmp1 = "", removed_tmp2 = "";

	for (int i = 1; i < N - 1; i++) {
		if (tmp1[i] != 'a' && tmp1[i] != 'e' && tmp1[i] != 'i' && tmp1[i] != 'o' && tmp1[i] != 'u')
			removed_tmp1 += tmp1[i];
	}

	for (int i = 1; i < N - 1; i++) {
		if (tmp2[i] != 'a' && tmp2[i] != 'e' && tmp2[i] != 'i' && tmp2[i] != 'o' && tmp2[i] != 'u')
			removed_tmp2 += tmp2[i];
	}

	if (removed_tmp1 != removed_tmp2) {
		cout << "NO";
		exit(0);
	}
}

int main() {
	cin.tie(NULL)->ios_base::sync_with_stdio(false);
	// freopen("input.txt", "r", stdin);

	cin >> N >> s1 >> s2;

	test1(s1, s2);
	test2(s1, s2);
	test3(s1, s2);

	cout << "YES";
	return 0;
}