#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#include <unordered_set>
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
map<char, string> m_en = {
	{'A', ".-"}, {'B', "-..."}, {'C', "-.-."}, {'D', "-.."}, {'E', "."}, {'F', "..-."},
	{'G', "--."}, {'H', "...."}, {'I', ".."}, {'J', ".---"}, {'K', "-.-"}, {'L', ".-.."},
	{'M', "--"}, {'N', "-."}, {'O', "---"}, {'P', ".--."}, {'Q', "--.-"}, {'R', ".-."},
	{'S', "..."}, {'T', "-"}, {'U', "..-"}, {'V', "...-"}, {'W', ".--"}, {'X', "-..-"},
	{'Y', "-.--"}, {'Z', "--.."}, {'_', "..--"}, {'.', "---."}, {',', ".-.-"}, {'?', "----"}
};
map<string, char> m_de = {
	{".-", 'A' }, { "-...", 'B' }, { "-.-.", 'C' }, { "-..", 'D' }, { ".", 'E' }, { "..-.", 'F' },
	{ "--.", 'G' }, { "....", 'H' }, { "..", 'I' }, { ".---", 'J' }, { "-.-", 'K' }, { ".-..", 'L' },
	{ "--", 'M' }, { "-.", 'N' }, { "---", 'O' }, { ".--.", 'P' }, { "--.-", 'Q' }, { ".-.", 'R' },
	{ "...", 'S' }, { "-", 'T' }, { "..-", 'U' }, { "...-", 'V' }, { ".--", 'W' }, { "-..-", 'X' },
	{ "-.--", 'Y' }, { "--..", 'Z' }, { "..--", '_' }, { "---.", '.' }, { ".-.-", ',' }, { "----", '?'}
};
//=========================//

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG

	string en;
	while (getline(cin, en)) {
		string morse = "", len = "", dec = "";

		for (char ch : en) {
			morse += m_en[ch];
			len += to_string(m_en[ch].length());
		}

		reverse(len.begin(), len.end());

		int idx = 0;
		for (char ch : len) {
			dec += m_de[morse.substr(idx, ch - '0')];
			idx += ch - '0';
		}

		cout << dec << '\n';
	}
}