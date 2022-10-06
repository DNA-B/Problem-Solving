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

	int n, m;
	int num = 0;
	int okjae;

	cin >> n >> m;
	cin >> okjae;

	cout << okjae / m << " " << okjae % m;
	return 0;
}
