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
int A = -1, B = -1;
//=========================//

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG

	int rep;
	vector<int> random_seq;

	for (int i = 1; i <= 10000; i++)
		random_seq.push_back(i);

	shuffle(random_seq.begin(), random_seq.end(), std::mt19937(42));

	for (int a = 0; a < 10000; a++) {
		cout << "? A " << random_seq[a] << '\n' << flush;
		cin >> rep;

		if (rep == 1) {
			A = random_seq[a];
			for (int b = 0; b < 10000; b++) {
				cout << "? B " << random_seq[b] << '\n' << flush;
				cin >> rep;

				if (rep == 1) {
					B = random_seq[b];
					cout << "! " << A + B << '\n' << flush;
					exit(0);
				}
			}
		}
	}
}