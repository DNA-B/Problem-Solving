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
int N, res = -1;
int score[26];
set<char> dict;
unordered_map<char, int> um;
vector<pair<int, char>> ranking;
vector<string> words;
//=========================//

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG

	cin >> N;

	string tmp;
	for (int i = 0; i < N; i++) {
		cin >> tmp;
		words.push_back(tmp);

		for (int j = tmp.size(); j > 0; j--) {
			int idx = tmp.size() - j;
			score[tmp[idx] - 'A'] += pow(10, j - 1);
			dict.insert(tmp[idx]);
		}
	}

	for (char num : dict)
		ranking.push_back({ score[num - 'A'], num });

	sort(ranking.begin(), ranking.end(), greater<>());

	int cnt = 9;
	for (int i = 0; i < ranking.size(); i++)
		um[ranking[i].Y] = cnt--;

	int total = 0;
	for (string word : words) {
		for (int i = word.size(); i > 0; i--) {
			int idx = word.size() - i;
			total += um[word[idx]] * pow(10, i - 1);
		}
	}

	cout << total;
}