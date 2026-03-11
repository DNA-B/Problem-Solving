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
int Sab, Ma, Fab, Mb;
//=========================//

// 구간 s를 이용할 때, 고속철도를 이용했을 때보다 항공편을 이용했을 때 소요 시간이 같거나 더 오래 걸립니다.
bool checkCondition1(int minuteTrain, int minuteAirplane) {
	return minuteTrain <= minuteAirplane;
}

// 이용객 p는 철도를 좋아합니다.그리고, 고속철도로 구간 s를 주파하는 데 소요 시간이 4시간 이하입니다.
bool checkCondition1(int minute) {
	return minute <= 4 * 60;
}

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG

	cin >> Sab >> Ma >> Fab >> Mb;

	if (checkCondition1(Sab, Ma + Fab + Mb) || checkCondition1(Sab))
		cout << "high speed rail";
	else
		cout << "flight";
}