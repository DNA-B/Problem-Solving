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
int N;
string study;
vector<string> boj, etc;
//=========================//

bool cmp(string& a, string& b) {
	if (a.length() == b.length())
		return a < b;
	return a.length() < b.length();
}

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG

	cin >> N;
	cin.ignore();

	for (int i = 0; i < N; i++) {
		getline(cin, study);
		if (study.length() >= 7 && study.substr(0, 7) == "boj.kr/")
			boj.push_back(study);
		else
			etc.push_back(study);
	}

	sort(boj.begin(), boj.end(), cmp);
	sort(etc.begin(), etc.end(), cmp);

	for (string s : etc) cout << s << '\n';
	for (string s : boj) cout << s << '\n';
}