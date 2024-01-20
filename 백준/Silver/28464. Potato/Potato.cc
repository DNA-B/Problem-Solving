#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

using namespace std;

int N, a;
int yang = 0, park = 0;
multiset<int> s;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	// freopen("input.txt", "r", stdin);

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> a;
		s.insert(a);
	}

	for (int i = 0; i < N; i++)
	{
		if (i % 2 == 0) // 박모씨 -> 최대
		{
			park += *(--s.end());
			s.erase(--s.end());
		}
		else // 양모씨 -> 최소
		{
			yang += *(s.begin());
			s.erase(s.begin());
		}
	}

	cout << yang << " " << park;

	return 0;
}