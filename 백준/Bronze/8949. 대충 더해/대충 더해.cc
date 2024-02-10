#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

using namespace std;

string A, B;
vector<int> v; // 각 자리수의 합
string ans;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	// freopen("input.txt", "r", stdin);

	cin >> A >> B;

	if (A.size() < B.size())
	{
		while (A.size() != B.size())
			A.insert(A.begin(), '0');
	}
	else
	{
		while (A.size() != B.size())
			B.insert(B.begin(), '0');
	}

	for (int i = 0; i < A.size(); i++)
	{
		int n_sum = (A[i] - '0') + (B[i] - '0');
		v.push_back(n_sum);
	}

	for (auto item : v)
		ans += to_string(item);

	cout << ans;

	return 0;
}