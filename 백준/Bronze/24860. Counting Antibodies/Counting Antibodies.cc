#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	long long vk, jk, vl, jl, vh, dh, jh;
	cin >> vk >> jk >> vl >> jl >> vh >> dh >> jh;

	cout << ((vk * jk) + (vl * jl)) * (vh * dh * jh);

	return 0;
}