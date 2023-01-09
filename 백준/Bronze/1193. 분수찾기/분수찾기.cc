#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
	int x;
	int idx = 1; // idx번 째 대각선

	cin >> x;

	while (x > idx) 
	{
		x -= idx;
		idx++;
	}

	// 분자 + 분모 = idx + 1
	if (idx % 2 != 0) 
		cout << (idx + 1) - x << '/' << x;
	else
		cout << x << '/' << (idx + 1) - x;
		


    return 0;
}