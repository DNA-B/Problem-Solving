#define _CRT_SECURE_NO_WARNINGS
#define BOUND 301
#define first X
#define second Y

#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	// freopen("input.txt", "r", stdin);

	while (true) {
		int ans = 1; // 왼쪽 여백 1cm 주고 시작
		string license_plate;

		cin >> license_plate;

		if (license_plate == "0")
			break;

		for (char ch : license_plate) {
			switch (ch) {
				case '0':
					ans += 4;
					break;
				case '1':
					ans += 2;
					break;
				default:
					ans += 3;
					break;
			}

			ans++; // 숫자 사이 여백 1cm
		}

		cout << ans << "\n";
	}

	return 0;
}