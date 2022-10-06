#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	string arr;

	while (1)
	{
		getline(cin, arr);
		if (arr == "END") return 0;

		reverse(arr.begin(), arr.end());
		cout << arr << "\n";
	}


	return 0;
}