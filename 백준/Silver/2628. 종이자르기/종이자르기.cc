#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

using namespace std;

/******** MACRO ********/
#define BOUND 10001
#define INF 0x3f3f3f3f
#define MOD 1'000'000'007
#define PI 3.1415926535897932
#define ll long long
#define X first
#define Y second
/***********************/

/****** VARIABLEs ******/
int N, M, C;
int max_garo = -1, max_sero = -1;
vector<int> cut_garo(1, 0), cut_sero(1, 0);
/***********************/

int main() {
	cin.tie(NULL)->ios_base::sync_with_stdio(false);
	// freopen("input.txt", "r", stdin);

	cin >> M >> N >> C;

	for (int i = 0; i < C; i++) {
		int order, cut;
		cin >> order >> cut;
		order == 1 ? cut_sero.push_back(cut) : cut_garo.push_back(cut);
	}

	cut_sero.push_back(M); // 세로로 자르면 가로의 길이를 넣는 것
	cut_garo.push_back(N); // 가로로 자르면 세로의 길이를 넣는 것
	sort(cut_sero.begin(), cut_sero.end());
	sort(cut_garo.begin(), cut_garo.end());

	for (int i = 1; i < cut_sero.size(); i++) {
		if (cut_sero[i] - cut_sero[i - 1] > max_sero)
			max_sero = cut_sero[i] - cut_sero[i - 1];
	}

	for (int i = 1; i < cut_garo.size(); i++) {
		if (cut_garo[i] - cut_garo[i - 1] > max_garo)
			max_garo = cut_garo[i] - cut_garo[i - 1];
	}

	cout << max_sero * max_garo;
	return 0;
}