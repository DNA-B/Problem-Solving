#include <bits/stdc++.h>
#define INF 0x3f3f3f3f

using namespace std;

int mem[1000001] = { 0 };

int make_one(int n)
{
	if (n == 1)
		return 0;

	if (mem[n] != 0)
		return mem[n];
	else
	{
		mem[n] = make_one(n - 1) + 1; // n-1을 먼저 계산해놓고

		if (!(n % 3))
			mem[n] = min(mem[n], make_one(n / 3) + 1); // 3일때 비교
		
		if (!(n % 2))
			mem[n] = min(mem[n], make_one(n / 2) + 1); // 2일때 비교 + 3과 2의 공통 배수라도 같이 검사 가능
		
		return  mem[n];
	}
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
	int n;

	cin >> n;
	cout << make_one(n);
    
	return 0;
}