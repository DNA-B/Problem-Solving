#include<bits/stdc++.h>
#include<regex>

#define INF 0x3f3f3f3f

using namespace std;

string pt;
int zero, one, cur_zero, cur_one;


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> pt;

    zero = count(pt.begin(), pt.end(), '0');
    one = count(pt.begin(), pt.end(), '1');

    for (int i = 0; i < pt.length(); i++) // 사전순으로 앞이기 때문에 0이 최대한 앞쪽에 위치해야 한다. -> 1을 앞에서부터 먼저 제거해 준다.
    {
        if (pt[i] == '1' && cur_one < (one / 2))
        {
            pt.erase(i, 1);
            cur_one++;
            i--;
        }
    }

    for (int i = pt.length() - 1; i >= 0; i--) // -> 0은 뒤에서 부터 제거해줌으로써 앞의 0을 최대한 남겨준다.
    {
        if (pt[i] == '0' && cur_zero < (zero / 2))
        {
            pt.erase(i, 1);
            cur_zero++;
            i++;
        }
    }

    cout << pt;

    return 0;
}