#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

using namespace std;

string s;
int max_cnt = -1;
int idx = -1;
int arr[26] = { 0 };

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	// freopen("input.txt", "r", stdin);

	cin >> s;

	for (int i = 0; i < s.size(); i++)
		arr[toupper(s[i]) - 65]++;

	for (int i = 0; i < 26; i++) {
		if (arr[i] > max_cnt) {
			max_cnt = arr[i];
			idx = i;
		}
	}

	if (count(arr, arr + 26, max_cnt) == 1)
		cout << (char)(idx + 65);
	else
		cout << '?';

	return 0;
}