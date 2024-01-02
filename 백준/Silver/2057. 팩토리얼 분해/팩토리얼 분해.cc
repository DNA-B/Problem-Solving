#include <bits/stdc++.h>

using namespace std;

/*
* N의 범위가 1,000,000,000,000,000,000
* 20!의 값이 2,432,902,008,176,640,000
* 그렇다면 1!~19!의 값으로 브루트포스를 해보자.
*/

long long N;
long long fact[] = { 1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880,
					3628800, 39916800, 479001600, 6227020800, 87178291200, 1307674368000,
					20922789888000, 355687428096000, 6402373705728000, 121645100408832000 };
bool is_used[20];
bool ans = false;

void solve(int cur, long long total)
{
	if (total == N)
		ans = true;
	else if (total > N)
		return;

	for (int i = cur; i < 20; i++)
	{
		if (fact[i] > N)
			return;

		if (!is_used[i])
		{
			is_used[i] = true;
			solve(i + 1, total + fact[i]);
			is_used[i] = false;
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;

	for (int i = 0; i < 20; i++)
	{
		if (fact[i] > N)
			break;

		is_used[i] = true;
		solve(i + 1, fact[i]);
		is_used[i] = false;
	}

	if (ans)
		cout << "YES";
	else
		cout << "NO";

	return 0;
}