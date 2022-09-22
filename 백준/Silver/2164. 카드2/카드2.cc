
#include <iostream>
#include <cctype>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <string>
#include <queue>

using namespace std;

// 2164번 : 카드2
// vector로 덱 구현

int main()
{
	queue<int> q;
	int n;
	int temp;

	scanf("%d", &n);

	for (int i = 1; i <= n; i++)
	{
		q.push(i);
	}

	while (q.size() != 1)
	{
		q.pop(); // 삭제

		temp = q.front(); // 앞에 값 저장
		q.pop(); // 삭제

		q.push(temp); // 뒤에 삽입
	}

	printf("%d", q.front());

	return 0;
}