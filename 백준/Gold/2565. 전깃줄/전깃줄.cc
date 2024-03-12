#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

using namespace std;

int N, A, B;
vector<pair<int, int>> v;
vector<int> LIS;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	// freopen("input.txt", "r", stdin);

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> A >> B;
		v.push_back({ A, B });
	}

	sort(v.begin(), v.end());

	for (auto item : v)
	{
		if (LIS.empty() || LIS.back() < item.second)
			LIS.push_back(item.second);
		else
			*lower_bound(LIS.begin(), LIS.end(), item.second) = item.second;
	}

	cout << N - LIS.size();

	return 0;
}