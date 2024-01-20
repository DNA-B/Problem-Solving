#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

using namespace std;

int N, K;
int arr[11];
bool is_used[11];
int comb[5];
set<int> s;

void solve(int cur)
{
	if (cur == K)
	{
		string tmp = "";

		for (int i = 0; i < K; i++)
			tmp += to_string(comb[i]);

		s.insert(stoi(tmp));
		return;
	}

	for (int i = 0; i < N; i++)
	{
		if (!is_used[i])
		{
			is_used[i] = true;
			comb[cur] = arr[i];
			solve(cur + 1);
			is_used[i] = false;
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	// freopen("input.txt", "r", stdin);

	cin >> N >> K;

	for (int i = 0; i < N; i++)
		cin >> arr[i];

	solve(0);

	cout << s.size();

	return 0;
}