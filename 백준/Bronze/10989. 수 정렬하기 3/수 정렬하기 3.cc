#include <iostream>
#include <cctype>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <string>

using namespace std;

// 11989번 : 수 정렬하기 3
int main()
{
	int n;
	int x;
	int arr[10001] = { 0 }; // 카운트 정렬 변수

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		scanf("%d", &x);
		arr[x]++; // 나온 값들을 카운팅
	}

	// 1부터 확인하면 자동 오름차순 정렬
	// 내림차순은 10000부터

	for (int i = 1; i < 10001; i++) // 카운팅만큼 1부터 10000까지 출력
	{
		for (int j = 0; j < arr[i]; j++)
		{
			printf("%d\n", i);
		}
	}

	return 0;
}