#include <iostream>
#include <algorithm> 
#include <string> 
// #include <cctype> 
// #include <cmath> 
// #include <queue>
// #include<deque>
// #include <set>
#include <vector>
// #include <list>
#include <stack> 
// #include <bitset>

using namespace std;

int main()// 에디터랑 비슷한 풀이
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	stack<int> st;
	int rep;
	int n;
	long long sum = 0;

	cin >> rep;

	while (rep)
	{
		cin >> n;

		if (n != 0)
		{
			st.push(n);
		}
		else
		{
			st.pop();
		}
		rep--;
	}

	while (!(st.empty()))
	{
		sum += st.top();
		st.pop();
	}

	cout << sum;

	return 0;
}