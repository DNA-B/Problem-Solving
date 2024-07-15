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
int hi, hi_idx;
vector<int> score(50);
/***********************/

int main() {
	cin.tie(NULL)->ios_base::sync_with_stdio(false);
	// freopen("input.txt", "r", stdin);

	for (int i = 0; i < 50; i++)
		cin >> score[i];

	cin >> hi;

	hi_idx = find(score.begin(), score.end(), hi) - score.begin();
	hi_idx++;

	if (0 < hi_idx && hi_idx <= 5)
		cout << "A+";
	else if (5 < hi_idx && hi_idx <= 15)
		cout << "A0";
	else if (15 < hi_idx && hi_idx <= 30)
		cout << "B+";
	else if (30 < hi_idx && hi_idx <= 35)
		cout << "B0";
	else if (35 < hi_idx && hi_idx <= 45)
		cout << "C+";
	else if (45 < hi_idx && hi_idx <= 48)
		cout << "C0";
	else
		cout << "F";

	return 0;
}