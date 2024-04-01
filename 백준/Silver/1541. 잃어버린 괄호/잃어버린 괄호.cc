#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

using namespace std;

string formula, tmp = "";
int ans = 0;
bool is_minus = false;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	// freopen("input.txt", "r", stdin);

	cin >> formula;

	for (int i = 0; i <= formula.size(); i++) {
		if (i == formula.size() || formula[i] == '-' || formula[i] == '+') {
			ans = is_minus ? (ans - stoi(tmp)) : (ans + stoi(tmp));
			tmp = "";
		}
		else {
			tmp += formula[i];
		}

		if (formula[i] == '-') // (50 - 20 + 30)이라면 첫 숫자인 50이 -50으로 들어가면 안되므로 맨 끝에 배치
			is_minus = true; // '-' 이후의 값들은 모두 괄호로 묶어 (-(A + B) = -C)와 같이 만들어 버리는 것이다.
	}

	cout << ans;

	return 0;
}