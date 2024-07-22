#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

using namespace std;

/******** MACRO ********/
#define INF 0x3f3f3f3f
#define LLINF 1e18
#define MOD 1'000'000'007
#define PI 3.1415926535897932
#define ll long long
#define X first
#define Y second
/***********************/

/****** VARIABLEs ******/
int T, N, M; // 자동차 종류, 사건 기록
/***********************/

int main() {
	cin.tie(NULL)->ios_base::sync_with_stdio(false);
	// freopen("input.txt", "r", stdin);

	cin >> T;

	while (T--) {
		map<string, tuple<int, int, int>> car; // {차종 <원가, 대여비, 1km당 추가 비용>}
		map<string, ll> bill;
		map<string, int> state; // state가 -1이면 INCONSISTENT, 0이면 p, 1이면 a, 2면 r
		map<string, string> rent_car;

		cin >> N >> M;

		for (int i = 0; i < N; i++) {
			string cname;
			int price, rental, per;

			cin >> cname >> price >> rental >> per;
			car[cname] = { price, rental, per };
		}

		for (int i = 0; i < M; i++) {
			string aname, some, akind;
			int atime;

			cin >> atime >> aname >> akind >> some; // p면 some은 차종, a면 파손율, r이면 주행 거리

			if (state.find(aname) != state.end() && state[aname] == -1)
				continue;

			if (akind == "p") {
				if (state.find(aname) != state.end() && state[aname] != 2) {
					state[aname] = -1;
					continue;
				}
				state[aname] = 0;
				rent_car[aname] = some;
				bill[aname] += get<1>(car[some]); // 대여비
			}
			else if (state.find(aname) == state.end()) {
				state[aname] = -1;
				continue;
			}
			else if (akind == "a") {
				if (state[aname] != 0 && state[aname] != 1) {
					state[aname] = -1;
					continue;
				}
				state[aname] = 1;
				bill[aname] += (get<0>(car[rent_car[aname]]) * stoll(some) + 99) / 100; // 원가 * 파손율;
			}
			else if (akind == "r") {
				if (state[aname] == 2) {
					state[aname] = -1;
					continue;
				}
				state[aname] = 2;
				bill[aname] += get<2>(car[rent_car[aname]]) * stoll(some);
			}
		}

		for (auto item : state) {
			if (item.Y != 2) // 반납을 안했다면
				cout << item.X << " " << "INCONSISTENT\n";
			else
				cout << item.X << " " << bill[item.X] << "\n";
		}
	}

	return 0;
}