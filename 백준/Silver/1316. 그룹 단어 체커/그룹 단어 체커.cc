#include <bits/stdc++.h>
#define npos string::npos

using namespace std;

vector<int>v(26);
int n;
int res = 0;
string str;
bool flag = true;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
 
    for (int i = 0; i < n; i++)
    {
        fill(v.begin(), v.end(), 0);
        cin >> str;
        
        v[str[0] - 'a']++; // 첫 번째 문자 카운팅

        for (int j = 1; j < str.length(); j++)
        {
            if (str[j - 1] != str[j] && v[str[j] - 'a'] != 0) // 앞 문자와 내 문자가 다른데 내 문자가 이미 등장했었다면
                flag = false;
            else
                v[str[j] - 'a']++;
        }

        if (flag)
            res++;

        flag = true;
    }
  
    cout << res;

    return 0;
}