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
string var, new_var = "";
//=========================//

bool is_error(int i) {
	if ((i == 0 || i == var.size() - 1) && var[i] == '_') // 맨 앞이나 뒤에 '_' X
		return true;
	else if (var[i] == '_' && var[i + 1] == '_') // '_' 연속 2개
		return true;
	else if (var[i] == '_' && isupper(var[i + 1])) // '_' 뒤에 대문자
		return true;
	else if (i == 0 && isupper(var[i])) // 맨 앞 대문자 X
		return true;

	return false;
}

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG

	cin >> var;

	bool java = false, cpp = false;
	for (int i = 0; i < var.size(); i++) {
		if (is_error(i)) {
			cout << "Error!";
			exit(0);
		}

		if (var[i] == '_') {
			cpp = true;
			new_var += toupper(var[i + 1]);
			i++;
		}
		else if (isupper(var[i])) {
			java = true;
			new_var += '_';
			new_var += tolower(var[i]);
		}
		else {
			new_var += var[i];
		}
	}

	if (java && cpp) // 두 개 혼용
		cout << "Error!";
	else
		cout << new_var;
}