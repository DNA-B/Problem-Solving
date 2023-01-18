#include <bits/stdc++.h>

using namespace std;

/*
BOJ 1620 : 나는야 포켓몬 마스터 이다솜
- 만약 O(1)에 find를 하지 못한다면 시간초과
- 그렇기 때문에 dict를 by name과 by num 2개로 만든다.
- 이렇게 하면 숫자, 이름 상관없이 탐색이 O(1)에 완료된다.
*/

int n, m;
unordered_map<string, int> dict_name;
unordered_map<int, string> dict_num;
string search_str;
string poketmon_name;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for (int i = 1; i <= n; i++)
    {
        cin >> poketmon_name;
        dict_name[poketmon_name] = i;
        dict_num[i] = poketmon_name;
    }

    while (m--)
    {
        cin >> search_str;

        if (search_str[0] >= 'A' && search_str[0] <= 'Z')
            cout << dict_name[search_str] << "\n";
        else
            cout << dict_num[stoi(search_str)] << "\n";
    }

    return 0;
}