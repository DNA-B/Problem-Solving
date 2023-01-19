#include <bits/stdc++.h>

using namespace std;

int mem[1000001];
int path[1000001];
int n;

void find_path(int cur)
{
	cout << cur << " ";
	
	if (cur == 1)
		return;
	else
		find_path(path[cur]);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
	cin >> n;
	
	mem[1] = 0;

	for (int i = 2; i <= n; i++)
	{
		mem[i] = mem[i - 1] + 1;
		path[i] = i - 1;

		if (i % 2 == 0 && (mem[i] > mem[i / 2] + 1))
		{
			mem[i] = mem[i / 2] + 1;
			path[i] = i / 2;
		}

		if (i % 3 == 0 && (mem[i] > mem[i / 3] + 1))
		{
			mem[i] = mem[i / 3] + 1;
			path[i] = i / 3;
		}
	}

	cout << mem[n] << "\n";
	find_path(n);
	
	return 0;
}