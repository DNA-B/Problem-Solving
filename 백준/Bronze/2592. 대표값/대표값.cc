#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

#define BOUND 1001
#define ll long long
#define first X
#define second Y

using namespace std;

int arr[11];
int cnt[1001];
int mean = -1, mode = -1, mode_cnt = -1;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	// freopen("input.txt", "r", stdin);

	for (int i = 0; i < 10; i++) {
		cin >> arr[i];
		cnt[arr[i]]++;
	}

	mean = accumulate(arr, arr + 10, 0) / 10;

	for (int i = 0; i < 10; i++) {
		if (cnt[arr[i]] > mode_cnt) {
			mode_cnt = cnt[arr[i]];
			mode = arr[i];
		}
	}

	cout << mean << "\n" << mode;

	return 0;
}