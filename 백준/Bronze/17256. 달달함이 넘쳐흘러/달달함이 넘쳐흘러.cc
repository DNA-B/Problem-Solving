#include <iostream>
#include <algorithm> 
#include <string> 
// #include <numeric>
// #include <cctype> 
// #include <cmath>
// #include <stack> 
// #include <queue>
// #include <deque>
// #include <list>
// #include <set>
#include <vector>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int ax, ay, az;
	int cx, cy, cz;
	int bx, by, bz;

	cin >> ax >> ay >> az >> cx >> cy >> cz;

	bx = cx - az;
	by = cy / ay;
	bz = cz - ax;

	cout << bx << " " << by << " " << bz;

	return 0;
}
