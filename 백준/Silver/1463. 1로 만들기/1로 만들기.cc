#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm> // swap(a, b) : 교환
#include <string> //string : strstr(s1, s2) 포함되면 위치 반환, strupr 대문자 변환, strcspn(s1, s2) s2가 s1에서 연속으로 발견
#include <cctype> // isalpha, isdigit, islower, isupper, tolower, toupper, ispunct
#include <cstring>
#include <cstdlib> // atoi, atol, atof, itoa
#include <cmath> // abs, gcd(최대공약수), lcm(최소공배수), max(x,y,z), 
#include <vector>
#include <queue>
#include <stack>// reverse(start, end): 뒤집기, sort(start, end) 정렬, max_element(start, end) : 최댓값, v.erase(x) : x 삭제
#include <bitset>//bit.set(n, true/false) : 전체 1 세팅, bit.size() : 크기, bit.none() : 모두 0이면 1, bit.any() : 하나라도 1이면 1, bit.flip(n) : 전체 반전, bit.to_string() : 문자열 변환

using namespace std;

int mem[1000001] = { 0 };

int make_one(int n)
{
	if (n == 1)
	{
		return 0;
	}

	if (mem[n] != 0)
	{
		return mem[n];
	}
	else // 단계적으로
	{
		mem[n] = make_one(n - 1) + 1; // n-1을 먼저 계산해놓고

		if (!(n % 3))
		{
			mem[n] = min(mem[n], make_one(n / 3) + 1); // 3일때 비교
		}
		
		if (!(n % 2))
		{
			mem[n] = min(mem[n], make_one(n / 2) + 1); // 2일때 비교 + 3과 2의 공통 배수라도 같이 검사 가능
		}
		
		return  mem[n];
	}
}

int main()
{
	int n;

	cin >> n;
	cout << make_one(n);
	return 0;
}