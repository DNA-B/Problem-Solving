#define _CRT_SECURE_NO_WARNINGS

#include <iostream> // C++ library
#include <algorithm>
#include <string>
#include <cctype> // C library
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <vector> // STL
#include <queue>
#include <stack>
#include <list>

using namespace std;

int main()
{
	int num = 0;
	int x;

	scanf("%d", &num);

	vector <int> v;

	for (int i = 0; i < num; i++)
	{
		scanf("%d", &x);
		v.push_back(x);
	}
	
	sort(v.begin(), v.end());

	for (int v_num : v)
	{
		printf("%d\n", v_num);
	}

	return 0;
}