#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main()
{
	/*
	- n이 5일때
	- 공백 : 4,3,2,1,0
	- 별 : 1,3,5,7,9
	- i : 0 1 2 3 4
	- 별(j)가 2씩 커진다.
	- i는 1씩 커진다.
	- line 28 : i를 0부터 시작했으므로 (i+1)을 해주고 여기에 x2를 해준다면 항상 j보다 1이 클 것이다.
	- line 23 :공백은 4 3 2 1 0이므로 5인 num에서 1을빼주고 거기서 i를 빼주면 될 것이다.
	*/

	int num;

	scanf("%d", &num);

	for (int i = 0; i < num; i++)
	{
		for (int j = (num - 1) - i; j > 0; j--)
		{
			printf(" ");
		}

		for (int j = 1; j < 2*(i+1); j++)
		{
			printf("*");
		}

		printf("\n"); // 줄바꿈
	}

	return 0;
}
