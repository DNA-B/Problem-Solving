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
string S;
int mx;
int chk[55], arr[55];
//=========================//

void solve(int idx, int cnt) {
	if (idx == S.size()) {
		for (int i = 0; i < cnt; i++)
			cout << arr[i] << ' ';
		exit(0);
	}

	string tmp = "";
	for (int i = idx; i < idx + 2; i++) {
		tmp += S[i];
		int itmp = stoi(tmp);

		if (itmp <= mx && !chk[itmp]) {
			chk[itmp] = 1;
			arr[cnt] = itmp;
			solve(i + 1, cnt + 1);
			chk[itmp] = 0;
		}
	}
}

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
	// freopen("input.txt", "r", stdin);

	cin >> S;

	// mx는 최대 자리 수, 문자열 길이가 10보다 큰 경우, 한 자릿수의 개수인 9 빼주고 이걸 2로 나누면 두 자릿수가 나오는 최대 경우의 수이다.
	mx = S.size() < 10 ? S.size() : 9 + ((S.size() - 9) / 2);
	solve(0, 0);
}