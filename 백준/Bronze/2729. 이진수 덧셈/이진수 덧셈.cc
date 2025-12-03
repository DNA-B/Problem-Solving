#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>

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
int T;
//=========================//

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG

	cin >> T;

	while (T--) {
		string A, B, res = "";

		cin >> A >> B;

		int carry = 0;
		int i = A.size() - 1;
		int j = B.size() - 1;
		while (i >= 0 || j >= 0 || carry) {
			int sum = carry;

			if (i >= 0)
				sum += A[i--] - '0';
			if (j >= 0)
				sum += B[j--] - '0';

			carry = sum / 2;
			res.push_back((sum % 2) + '0');
		}

		reverse(res.begin(), res.end());
		int idx = res.find_first_not_of('0');
		cout << (idx == -1 ? "0" : res.substr(idx)) << '\n';
	}
}