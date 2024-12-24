#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;
//========= MACRO =========//

//=========================//

//======= VARIABLEs =======//
string s;
unordered_map<string, string> um = {
	{"social", "digital humanities"},{"history", "digital humanities"},
	{"language", "digital humanities"}, {"literacy", "digital humanities"},
	{"bigdata", "public bigdata"},{"public", "public bigdata"},
	{"society", "public bigdata"} };
//=========================//

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
	//freopen("input.txt", "r", stdin);
	cin >> s; cout << um[s];
}