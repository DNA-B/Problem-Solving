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
string formula;
int A, B;
//=========================//

ll to_digit(string x) {
	ll ret = 0, p = x.length() - 1;
	bool is_nag = (x[0] == '-');

	for (int i = is_nag; i < x.length(); i++)
		ret = (ret * 8) + (x[i] - '0'); // Horner's Method
	return is_nag ? -ret : ret;
}

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG

	cin >> formula;

	int idx = formula.find_first_of("+-*/", 1); // (-1*1)과 같이 A가 음수일 수도 있음
	char op = formula[idx];
	string A = formula.substr(0, idx);
	ll A_digit = to_digit(A);
	string B = formula.substr(idx + 1);
	ll B_digit = to_digit(B);

	if (op == '/' && B == "0") {
		cout << "invalid";
		exit(0);
	}

	ll res;
	if (op == '+')
		res = A_digit + B_digit;
	else if (op == '-')
		res = A_digit - B_digit;
	else if (op == '*')
		res = A_digit * B_digit;
	else
		res = floor((1.0) * A_digit / B_digit);

	if (res < 0)
		cout << "-";
	cout << oct << abs(res); // 8진수 출력

}