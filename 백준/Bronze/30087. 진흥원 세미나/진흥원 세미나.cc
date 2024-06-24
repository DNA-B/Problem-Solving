#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

using namespace std;

/******** MACRO ********/
#define BOUND 100001
#define MOD 1'000'000'007
#define ll long long
#define X first
#define Y second
/***********************/

/****** VARIABLEs ******/
int N;
map<string, string> m = {
	{"Algorithm", "204"},
	{"DataAnalysis", "207"},
	{"ArtificialIntelligence", "302"},
	{"CyberSecurity", "B101"},
	{"Network", "303"},
	{"Startup", "501"},
	{"TestStrategy", "105"} };
/***********************/


int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	// freopen("input.txt", "r", stdin);

	cin >> N;

	while (N--) {
		string semina;

		cin >> semina;
		cout << m[semina] << "\n";
	}

	return 0;
}