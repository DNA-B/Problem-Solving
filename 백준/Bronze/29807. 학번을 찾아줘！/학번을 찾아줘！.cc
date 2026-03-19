#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>

using namespace std;

//========= MACRO =========//
#define PI 3.1415926535897932
#define INF 0x3f3f3f3f
#define LL_INF 1e18
#define ll long long
#define X first
#define Y second
//=========================//

//======= VARIABLEs =======//
int T;
int scores[5]; // { 국어, 수학, 영어, 탐구, 제2외국어 }
//=========================//

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG

	cin >> T;

	for (int i = 0; i < T; i++)
		cin >> scores[i];

	ll total = 0;

	if (scores[0] > scores[2])  // 국어 점수 vs 영어 점수
		total += (scores[0] - scores[2]) * 508;
	else
		total += (scores[2] - scores[0]) * 108;

	if (scores[1] > scores[3]) // 수학 점수 vs 탐구 점수
		total += (scores[1] - scores[3]) * 212;
	else
		total += (scores[3] - scores[1]) * 305;

	if (T == 5) // 제 2외국어 점수
		total += scores[4] * 707;

	cout << total * 4763;
}