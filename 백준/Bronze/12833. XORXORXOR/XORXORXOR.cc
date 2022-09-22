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
#include <bitset>

using namespace std;

int main() // XOR은 홀수일 때는 XOR을 짝수일 때는 기존 수가 나온다.
{
	int a, b, c;

	cin >> a >> b >> c;

	if (c % 2 == 0) 
	{
		cout << a;
	}
	else
	{
		cout << (a ^ b);
	}
	return 0;
}