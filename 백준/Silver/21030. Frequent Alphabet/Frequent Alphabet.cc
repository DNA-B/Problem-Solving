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
int N;
int alp[26];
string s1, s2;
//=========================//

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
	// freopen("input.txt", "r", stdin);

	cin >> N >> s1 >> s2;

	for (int i = 0; i < N; i++) {
		if (s1[i] == s2[i])
			alp[s1[i] - 'a']++;
		else {
			alp[s1[i] - 'a']++;
			alp[s2[i] - 'a']++;
		}
	}

	cout << *max_element(alp, alp + 26);
	return 0;
}