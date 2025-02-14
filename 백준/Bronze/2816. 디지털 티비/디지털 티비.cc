#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
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
int N, cur = 0;
string res = "";
string chan[105];
//=========================//

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG

	cin >> N;

	for (int i = 0; i < N; i++)
		cin >> chan[i];

	while (chan[cur] != "KBS1") { // KBS1 찾기
		res += '1';
		cur++;
	}

	while (cur != 0) {
		res += '4';
		swap(chan[cur], chan[cur - 1]);
		cur--;
	}

	while (chan[cur] != "KBS2") { // KBS2 찾기
		res += '1';
		cur++;
	}

	while (cur != 1) {
		res += '4';
		swap(chan[cur], chan[cur - 1]);
		cur--;
	}

	cout << res;
}