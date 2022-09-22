#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm> 
// #include <string> 
// #include <cctype> 
// #include <cmath> 
// #include <queue>
// #include<deque>
// #include <set>
 #include <vector>
// #include <stack> 
// #include <bitset>

using namespace std;

int main() // 구간 합, 부분 합
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int size, rep;
	int start, end;

	cin >> size >> rep;

	vector<int> v(size + 1);
	vector<int> sum(size + 1);

	v[0] = 0;
	for (int i = 1; i <= size; i++)
	{
		cin >> v[i];
	}
	

	sum[0] = 0;
	for (int i = 1; i <= size; i++) // 미리 그 구간의 합을 구해놓는다.
	{
		sum[i] = v[i] + sum[i - 1];
	}

	for (int i = 0; i < rep; i++) // 끝 구간에서 첫 구간 - 1을 해주면서 O(n)으로 구간 합을 구할 수 있다.
	{
		cin >> start >> end;
		cout << sum[end] - sum[start - 1] << "\n";
	}

	return 0;
}