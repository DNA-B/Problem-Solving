#include <bits/stdc++.h>

using namespace std;

int N;
int aeiou = 0;
string s;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> s;

	for (char ch : s)
	{
		if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
			aeiou++;
	}

	cout << aeiou;

	return 0;
}