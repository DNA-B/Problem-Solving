#include <iostream>
#include <algorithm> 
// #include <string> 
// #include <cctype> 
// #include <cmath> 
// #include <queue>
// #include<deque>
// #include <set>
 #include <vector>
// #include <stack> 
// #include <bitset>

using namespace std;

int counting(string str1, string str2, vector<int>& cnt1, vector<int>& cnt2)
{
	int diff = 0;
	
	for (int i = 0; i < str1.size(); i++)
	{
		cnt1[str1[i] - 'a']++;
	}

	for (int i = 0; i < str2.size(); i++)
	{
		cnt2[str2[i] - 'a']++;
	}
    
	for (int i = 0; i < 26; i++) // 만약 다르면 큰 값 - 작은 값 (ab, abb)여도 2-1하면 b하나만 지우는 경우 성립
	{
		if (cnt1[i] != cnt2[i])
		{
			diff += max(cnt1[i], cnt2[i]) - min(cnt1[i], cnt2[i]);
		}
	}

	return diff;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	string str1, str2;
	vector<int> str_cnt1(26); // str1 카운트 벡터
	vector<int> str_cnt2(26); // str2 카운트 벡터
	int diff = 0; // 다른 알파벳 개수

	cin >> str1 >> str2;

	diff = counting(str1, str2, str_cnt1, str_cnt2);
	
	if (diff == (str1.size() + str2.size())) // 문자열 길이들과 diff 변수값이 같은것은 모두 다르다는 뜻
	{
		cout << 0;
	}
	else
	{
		cout << diff;
	}

	return 0;
}