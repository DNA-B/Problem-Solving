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
int N, M;
string s, num;
ll arr[105];
//=========================//

ll gcd(int a, int b) {
	return b ? a : gcd(b, a % b);
}

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
	// freopen("input.txt", "r", stdin);

	cin >> N;
	cin.ignore();

	while (N--) {
		int M = 0, x = -1;
		ll mx = -1;

		getline(cin, s); // 한 줄 입력
		stringstream ss(s); // 문자열 스트림으로 변환

		while (getline(ss, num, ' ')) // 공백 기준으로 문자열 분리
			arr[M++] = stoi(num);

		for (int i = 0; i < M - 1; i++) {
			for (int j = i + 1; j < M; j++)
				mx = max(mx, gcd(arr[i], arr[j]));
		}

		cout << mx << '\n';
	}
}