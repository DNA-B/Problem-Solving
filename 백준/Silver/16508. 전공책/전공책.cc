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
string T;
int N;
int res = INT_MAX;
int T_cnt[26];
int book_cnt[20][26];
int book_price[20];
/***********************/

bool calc_price(vector<int> comb) {
	int comb_cnt[26] = { 0 };

	for (char ch : T) {
		for (int idx : comb)
			comb_cnt[ch - 'A'] += book_cnt[idx][ch - 'A'];

		if (comb_cnt[ch - 'A'] < T_cnt[ch - 'A'])
			return false;
	}

	return true;
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	// freopen("input.txt", "r", stdin);

	cin >> T >> N;

	for (char ch : T) // A면 25칸 왼쪽으로 이동시키고 1로 비트 설정
		T_cnt[ch - 'A']++;

	for (int i = 0; i < N; i++) {
		string book;
		cin >> book_price[i] >> book;

		for (char ch : book)
			book_cnt[i][ch - 'A']++;
	}

	for (int i = 0; i < (1 << N); i++) {
		int price = 0;
		vector<int> comb;

		for (int j = 0; j < N; j++) {
			if (i & (1LL << j)) {
				comb.push_back(j);
				price += book_price[j];
			}
		}

		if (calc_price(comb))
			res = min(res, price);
	}

	cout << (res == INT_MAX ? -1 : res);

	return 0;
}