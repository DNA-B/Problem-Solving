#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

using namespace std;

string s1, s2;
int ans;
vector<pair<string, int>> v = {
	{"M", 1000}, {"CM",900}, {"D", 500},
	{"CD",400}, {"C",100}, {"XC",90},
	{"L",50}, {"XL",40}, {"X",10},
	{"IX",9}, {"V",5}, {"IV",4},
	{"I",1}
};

int rtoi(string s) {
	int total = 0, idx = 0;
	string tmp;

	while (idx != s.size()) {
		for (auto item : v) {
			tmp = "";

			if (item.first.size() == 1) { // 1자리 문자
				if (s[idx] == *item.first.c_str()) {
					total += item.second;
					idx++;
					break;
				}
			}
			else { // 2자리 문자
				if (idx != s.size() - 1) {
					tmp += s[idx];
					tmp += s[idx + 1];

					if (tmp == item.first) {
						total += item.second;
						idx += 2;
						break;
					}
				}
			}
		}
	}

	return total;
}

string itor(int n) {
	string res = "";

	for (auto item : v) {
		while (n >= item.second) {
			n -= item.second;
			res += item.first;
		}
	}

	return res;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	// freopen("input.txt", "r", stdin);

	cin >> s1 >> s2;

	ans = rtoi(s1) + rtoi(s2);

	cout << ans << "\n";
	cout << itor(ans);

	return 0;
}