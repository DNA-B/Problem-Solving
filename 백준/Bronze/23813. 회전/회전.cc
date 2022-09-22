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

	string v[11];
	long long res = 0;
	int len;

	cin >> v[0];

	for (int i = 1; i <= v[0].size(); i++)

	{
		v[i] += v[i - 1][v[0].size() - 1];
		len = 1;



		while (len < v[0].size())

		{
			v[i] += v[i - 1][len - 1];
			len++;
		}
		res += stoll(v[i]);
	}

	cout << res;

	return 0;

}
