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
int cnt[26];
string s1, s2, s3;
//=========================//

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG

	cin >> s1 >> s2 >> s3;

	cnt[s1[0] - 'a']++;
	cnt[s2[0] - 'a']++;
	cnt[s3[0] - 'a']++;

	if (cnt['l' - 'a'] && cnt['k' - 'a'] && cnt['p' - 'a'])
		cout << "GLOBAL";
	else
		cout << "PONIX";
}