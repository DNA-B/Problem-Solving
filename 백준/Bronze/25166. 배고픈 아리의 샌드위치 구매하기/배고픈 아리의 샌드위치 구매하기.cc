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

int main()
{
	int ari = (1 << 10) - 1; // 1111111111
	int price;
	int kugi;

	cin >> price >> kugi;
	
	if (price <= ari) // 아리가 다 낼 경우
	{
		cout << "No thanks";
		return 0;
	}
	
	price -= ari;

	if (price > kugi) // 아리가 내고 남은 결제 금액이 쿠기의 돈 보다 클 경우
	{
		cout << "Impossible";
		return 0;
	}
	else
	{
		for (int subset = kugi; subset; subset = ((subset - 1) & kugi)) // 쿠기의 subset안에 결제 금액이 포함되는지 확인
		{
			if (subset == price)
			{
				cout << "Thanks";
				return 0;
			}
		}
		cout << "Impossible";
	}
	
	return 0;
}