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
		string sounds;
		unordered_map<string, bool> animals;

		cin.ignore();
		getline(cin, sounds);

		while (true) {
			string fox, say;
			string animal[3];
			cin >> animal[0] >> animal[1] >> animal[2];

			if (animal[1] == "does") {
				cin >> fox >> say;
				break;
			}

			animals[animal[2]] = true;
		}

		istringstream iss(sounds);
		string sound;

		while (iss >> sound)
			if (!animals[sound])
				cout << sound << ' ';
		cout << '\n';
	}
}