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
int N, M;
ll state[10];
pair<int, int> res = { 0, -1 }; // {연주 곡 수, 기타 수)
/***********************/

int bit_one(ll x) {
	int cnt = 0;

	for (int i = 0; i < max(N, M); i++)
		cnt += (x >> i) & 1;

	return cnt;
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	// freopen("input.txt", "r", stdin);

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		string guitar, songs;
		cin >> guitar >> songs;

		for (int j = M - 1; j >= 0; j--)
			state[i] = (state[i] << 1) | (songs[j] == 'Y'); // 한 칸씩 왼쪽으로 밀면서 Y인 노래 비트값 1로 설정
	}

	for (int i = 0; i < (1 << N); i++) { // 2^N개의 조합 확인
		int tmp_song, tmp_guitar;
		ll comb = 0;

		for (int j = 0; j < N; j++) {
			if ((i & (1LL << j)) != 0) // N개의 기타 중에 i에 속하는 기타들 확인
				comb |= state[j]; // 그 기타의 비트값들 모두 OR
		}

		tmp_song = bit_one(comb);
		tmp_guitar = bit_one(i);

		if (res.X < tmp_song)
			res = { tmp_song, tmp_guitar };
		else if (res.X == tmp_song && res.Y > tmp_guitar)
			res = { tmp_song, tmp_guitar };
	}

	cout << res.Y;

	return 0;
}