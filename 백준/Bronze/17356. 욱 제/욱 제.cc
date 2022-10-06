#include <bits/stdc++.h>

using namespace std;

#define PI 3.141592
int main()
{
	double w, j;
	double m;
	double p;

	cin >> w >> j;
	m = (j - w) / 400;
	p = 1 / (1 + pow(10, m));

	printf("%.4lf", p);
	
	return 0;
}