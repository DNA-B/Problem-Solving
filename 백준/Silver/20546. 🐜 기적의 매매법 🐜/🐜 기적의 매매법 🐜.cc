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
int money, JH, SM;
int MD[15];
//=========================//

int proc_JH() {
	int cur = money, stock = 0;

	for (int i = 0; i < 14; i++) {
		if (cur >= MD[i]) {
			stock += cur / MD[i];
			cur -= (cur / MD[i]) * MD[i];
		}
	}

	return cur + (stock * MD[13]);
}

int proc_SM() {
	int cur = money, stock = 0;
	int up_cnt = 0, down_cnt = 0;

	for (int i = 1; i < 14; i++) {
		if (MD[i] > MD[i - 1])
			up_cnt++;
		else
			up_cnt = 0;

		if (MD[i] < MD[i - 1])
			down_cnt++;
		else
			down_cnt = 0;

		if (up_cnt == 3) {
			cur += stock * MD[i];
			stock = 0;
        }

		if (down_cnt == 3) {
			stock += cur / MD[i];
			cur -= (cur / MD[i]) * MD[i];
		}
	}

	return cur + (stock * MD[13]);
}

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG

	cin >> money;

	for (int i = 0; i < 14; i++)
		cin >> MD[i];

	JH = proc_JH();
	SM = proc_SM();

	if (JH == SM)
		cout << "SAMESAME";
	else if (JH > SM)
		cout << "BNP";
	else
		cout << "TIMING";
}