#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int s1, s2, s3;
	int sum;

	cin >> s1 >> s2 >> s3;
	sum = s1 + s2 + s3;

	if (s1 == 60 && s1 == s2 && s2 == s3) 
	{
		printf("Equilateral");
	}
	else if (sum == 180 && (s1 == s2 || s2 == s3 || s3 == s1)) 
	{
		printf("Isosceles");
	}
	else if (sum == 180) 
	{
		printf("Scalene");
	}
	else
	{
		printf("Error");
	}

	return 0;
}