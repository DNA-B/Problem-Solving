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
string S;
unordered_map<char, string> keypad = {
	{'a', "2"}, {'b', "22"}, {'c', "222"},
	{'d', "3"}, {'e', "33"}, {'f', "333"},
	{'g', "4"}, {'h', "44"}, {'i', "444"},
	{'j', "5"}, {'k', "55"}, {'l', "555"},
	{'m', "6"}, {'n', "66"}, {'o', "666"},
	{'p', "7"}, {'q', "77"}, {'r', "777"}, {'s', "7777"},
	{'t', "8"}, {'u', "88"}, {'v', "888"},
	{'w', "9"}, {'x', "99"}, {'y', "999"}, {'z', "9999"}
};
//=========================//

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG


	while (cin >> S) {
		if (S == "halt")
			break;

		int t = 0;
		char prev = '\0';

		for (char ch : S) {
			if (prev == keypad[ch][0])
				t += 2;
			t += keypad[ch].size();
			prev = keypad[ch][0];
		}

		cout << t << '\n';
	}
}