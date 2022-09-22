#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	vector<int> v(1000001);
	int m, n;

	cin >> m >> n;

	for (int i = 2; i <= n; i++)
	{
		v[i] = i;
	}

	for (int i = 2; i * i <= n; i++) // 에라토스테네스의 체
	{
		if (v[i] == 0)
		{
			continue;
		}
		else
		{
			for (int j = i * i; j <= n; j += i) // i*i로 하면 O(nloglogn)
			{
				v[j] = 0;
			}
		}
	}
	
	for (int i = m; i <= n; i++)
	{
		if (v[i] != 0)
		{
			cout << v[i] << "\n";
		}
	}
	return 0;
}