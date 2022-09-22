#include <iostream>
#include <algorithm> 
#include <string> 
// #include <cctype> 
// #include <cmath> 
// #include <queue>
// #include<deque>
// #include <set>
#include <vector>
#include <list>
// #include <stack> 
// #include <bitset>

using namespace std;

int main()// 에디터랑 비슷한 풀이
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	string passward;

	cin >> n;

	while (n)
	{
		list<char> l; // 리스트 한 번 쓰고 비우려고 시작부분에서 매 번 초기화
		auto it = l.begin();

		cin >> passward;

		for (int i = 0; i < passward.size(); i++)
		{
			switch (passward[i])
			{
			case '<':
				if (it != l.begin())
				{
					it--;
				}
				break;
			case '>':
				if (it != l.end())
				{
					it++;
				}
				break;
			case '-':
				if (it != l.begin()) // (주의) l.empty()로 하면 begin일때 --를 하면서 DoubleFree가 발생 할 수 있다.
				{
					it--;
					it = l.erase(it);
				}
				break;
			default:
				l.insert(it, passward[i]); // iterator 자동 ++
				break;
			}
		}
		for (auto ch : l)
		{
			cout << ch;
		}
		cout << "\n";
		n--;
	}
	return 0;
}