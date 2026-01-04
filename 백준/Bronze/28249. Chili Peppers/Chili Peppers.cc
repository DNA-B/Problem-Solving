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
int N, total = 0;
unordered_map<string, int> SHU = {
	{"Poblano", 1500}, {"Mirasol", 6000}, {"Serrano", 15500},
	{"Cayenne", 40000}, {"Thai", 75000}, {"Habanero", 125000}
};
//=========================//

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG

	cin >> N;

	string pepper;
	while (N--) {
		cin >> pepper;
		total += SHU[pepper];
	}

	cout << total;
}