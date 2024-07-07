#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

using namespace std;

/******** MACRO ********/
#define BOUND 101
#define INF 0x3f3f3f3f
#define MOD 1'000'000'007
#define PI 3.1415926535897932
#define ll long long
#define X first
#define Y second
/***********************/

/****** VARIABLEs ******/
int N, M;
vector<string> a, b;
bool flag = true;
/***********************/

int main() {
	cin.tie(NULL)->ios_base::sync_with_stdio(false);
	// freopen("input.txt", "r", stdin);

	cin >> N >> M;
	a.resize(N);
	b.resize(M);

	for (string& s : a)
		cin >> s;

	for (string& s : b)
		cin >> s;

	for (int i = 0; i < N; i++) {
		string tmp = "";

		for (char ch : a[i]) {
			tmp += ch;
			tmp += ch;
		}

		if (tmp != b[i])
			flag = false;
	}

	cout << (flag ? "Eyfa" : "Not Eyfa");
	return 0;
}