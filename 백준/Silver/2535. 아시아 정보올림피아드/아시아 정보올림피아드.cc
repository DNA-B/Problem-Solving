#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

/******** MACRO ********/
#define INT_INF 0x3f3f3f3f
#define LL_INF 1e18
#define MOD 1'000'000'007
#define PI 3.1415926535897932
#define ll long long
#define X first
#define Y second
/***********************/
/****** VARIABLEs ******/
int N, cnt = 0;
int nation_cnt[101];
tuple<int, int, int> arr[101];
/***********************/


int main() {
	cin.tie(NULL)->ios_base::sync_with_stdio(false);
	// freopen("input.txt", "r", stdin);

	cin >> N;

	for (int i = 0; i < N; i++) {
		int nation, student, score;
		cin >> nation >> student >> score;
		arr[i] = { score, nation, student };
	}

	sort(arr, arr + N, greater<>());

	for (int i = 0; i < N; i++) {
		auto [score, nation, student] = arr[i];

		if (nation_cnt[nation] >= 2)
			continue;
		if (cnt == 3)
			break;
		nation_cnt[nation]++; cnt++;
		cout << nation << " " << student << "\n";
	}

	return 0;
}