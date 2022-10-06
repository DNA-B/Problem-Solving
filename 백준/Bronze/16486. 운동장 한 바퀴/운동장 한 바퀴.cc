#include <bits/stdc++.h>

using namespace std;

#define PI 3.141592
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	double d1, d2;

	scanf("%lf %lf", &d1, &d2);
	printf("%.6lf", (2 * d2 * PI) + (2 * d1));

	return 0;
}