#include <bits/stdc++.h>
#define INF 0x3f3f3f3f

using namespace std;

int arr[1001];
int mem[1001];
int N;
int ans = 0;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

	cin >> N;

	for (int i = 0; i < N; i++)
		cin >> arr[i];

	for (int i = 0; i < N; i++)
	{
		mem[i] = 1;
		for (int j = 0; j < i; j++)
		{
			if (arr[i] < arr[j])
				mem[i] = max(mem[i], mem[j] + 1);
		}
		ans = max(ans, mem[i]);
	}

	cout << ans;

    return 0;
}
