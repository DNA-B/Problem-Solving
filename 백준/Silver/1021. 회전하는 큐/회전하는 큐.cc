#include <bits/stdc++.h>

using namespace std;

int second(deque<int> d, int n)
{
	deque<int> temp = d;
	int count = 0;

	while (temp.front() != n)
	{
		temp.push_back(temp.front());
		temp.pop_front();
		count++;
	}

	return count;
}

int third(deque<int> d, int n)
{
	deque<int> temp = d;
	int count = 0;

	while (temp.front() != n)
	{
		temp.push_front(temp.back());
		temp.pop_back();
		count++;
	}

	return count;
}

void re_deque(deque<int>& d, int n, bool flag)
{
	if (flag) // 2번 작업
	{
		while (n--)
		{
			d.push_back(d.front());
			d.pop_front();
		}
		d.pop_front(); // 반복문이 끝나면 발견한 것이므로 pop해준다.
	}
	else // 3번 작업
	{
		while (n--)
		{
			d.push_front(d.back());
			d.pop_back();
		}
		d.pop_front();
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	deque<int> d;
	int n, m;
	int index[50] = { 0 };
	int res = 0;

	cin >> n >> m;
	
	for (int i = 1; i <= n; i++) // 들어가는 수는 각 원소의 번호
	{
		d.push_back(i);
	}

	for (int i = 0; i < m; i++) 
	{
		cin >> index[i];

		if (d.front() == index[i]) // front와 같을 때는 바로 꺼낸다. 2, 3 작업 수행 0번
		{
			d.pop_front();
		}
		else // 2번 작업과 3번 작업을 수행 했을 때의 최소값을 비교하여 deque 수정
		{
			res += min(second(d, index[i]), third(d, index[i]));
			second(d, index[i]) < third(d, index[i]) ? re_deque(d, second(d, index[i]), true) : re_deque(d, third(d, index[i]), false);
		}
	}

	cout << res;

	return 0;
}