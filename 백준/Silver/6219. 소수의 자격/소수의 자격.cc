#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

/******** MACRO ********/
#define PI 3.1415926535897932
#define MOD 1000000007
#define INT_INF 0x3f3f3f3f
#define LL_INF 1e18
#define ll long long
#define X first
#define Y second
/***********************/

/****** VARIABLEs ******/
int A, B, D, cnt = 0;
bool is_not_prime[4000005];
vector<int> prime;
/***********************/

void era() {
	is_not_prime[0] = is_not_prime[1] = true;
	for (int i = 2; i <= sqrt(B); i++) {
		if (is_not_prime[i]) continue;
		for (int j = i * i; j <= B; j += i)
			is_not_prime[j] = true;
	}

	for (int i = A; i <= B; i++) {
		if (!is_not_prime[i])
			prime.push_back(i);
	}
}

bool is_include(string& s) {
	for (char& ch : s)
		if (ch - '0' == D) return true;
	return false;
}

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
	// freopen("input.txt", "r", stdin);

	cin >> A >> B >> D;
	era();

	for (int& item : prime) {
		string tmp = to_string(item);
		cnt += is_include(tmp);
	}

	cout << cnt;
	return 0;
}