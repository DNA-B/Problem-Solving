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

int main()
{
	int n;
	bitset<32> plus_n;
	bitset<32> minus_n;
	bitset<32> count = 0;
	
	cin >> n;
	
	plus_n = bitset<32>(n);
	minus_n = ~n + 1; // 2의 보수

	count = (plus_n ^ minus_n); // 다른 것만 1로 변경

	cout << count.count(); // 1 개수 세기
	return 0;
}