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
string phrase;
vector<string> v[105], cv[105];
unordered_map<string, int> um;
//=========================//

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG

	cin >> N;
	cin.ignore();

	for (int i = 1; i <= N; i++) {
		getline(cin, phrase);

		int idx = 1;
		string word;
		stringstream ss(phrase);
		while (getline(ss, word, ' ')) {
			v[i].push_back(word);
			um[word] = i;
		}
	}

	getline(cin, phrase);
	string word;
	stringstream ss(phrase);
	while (getline(ss, word, ' ')) {
		if (!um[word]) {
			cout << "Impossible";
			exit(0);
		}
		cv[um[word]].push_back(word);
	}

	for (int i = 1; i <= N; i++) {
		if (v[i] != cv[i]) {
			cout << "Impossible";
			exit(0);
		}
	}

	cout << "Possible";
}