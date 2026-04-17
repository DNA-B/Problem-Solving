#include <iostream>
using namespace std;

int X, Y;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> X >> Y;
	if (X > 7) cout << X - 7;
	else cout << Y + 7;
}