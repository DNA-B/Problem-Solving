#include<bits/stdc++.h>

using namespace std;

int gcd(int a, int b)
{
	if (b == 0) 
		return a;
	else
		return gcd(b, a % b);
}

int lcm(int a, int b)
{
	return (a * b) / gcd(a, b);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    string a, b;
	string tmp_a, tmp_b;

    cin >> a >> b;

	int len_lcm = lcm(a.length(), b.length());

	for (int i = 0; i < len_lcm / a.size(); i++)
		tmp_a += a;

	for (int i = 0; i < len_lcm / b.size(); i++)
		tmp_b += b;

	if (tmp_a == tmp_b) 
		cout << 1;
	else 
		cout << 0;

    return 0;
}