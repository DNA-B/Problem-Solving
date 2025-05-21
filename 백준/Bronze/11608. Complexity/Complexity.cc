#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#include <unordered_set>
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
int cnt = 0, res = 0;
int alp[26];
vector<int> freq;
//=========================//

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG

	cin >> S;

	for (char ch : S)
		alp[ch - 'a']++;

	for (int i = 0; i < 26; i++) {
		if (alp[i]) {
			freq.push_back(alp[i]);
			cnt++;
		}
	}

	sort(freq.begin(), freq.end());

	for (int i = 0; i < cnt - 2; i++)
		res += freq[i];

	cout << res;
}