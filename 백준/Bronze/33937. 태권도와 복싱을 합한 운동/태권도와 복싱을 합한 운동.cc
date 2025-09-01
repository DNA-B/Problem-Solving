#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#include <unordered_map>
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
string A, B;
string pre_A = "", pre_B = "";
//=========================//

bool is_aeiou(char ch) {
	return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
}

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG

	cin >> A >> B;

	for (int i = 0; i < A.length() - 1; i++) {
		if (is_aeiou(A[i]) && !is_aeiou(A[i + 1])) {
			pre_A = A.substr(0, i + 1);
			break;
		}
	}

	for (int i = 0; i < B.length() - 1; i++) {
		if (is_aeiou(B[i]) && !is_aeiou(B[i + 1])) {
			pre_B = B.substr(0, i + 1);
			break;
		}
	}

	if (pre_A == "" || pre_B == "")
		cout << "no such exercise\n";
	else
		cout << pre_A + pre_B;
}