#include <iostream>
#include <cctype>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <string>
#include <queue>

using namespace std;

// 11050번 : 이항 계수
// ( n! / ( k! * (n-k)! ) )

int fact(int n)
{
	if (n == 0)
	{
		return 1;
	}
	else
	{
		return n * fact(n - 1);
	}
}

int main()
{
	int n;
	int k;

	cin >> n >> k;

	cout << fact(n) / (fact(k) * fact(n - k));

	return 0;
}