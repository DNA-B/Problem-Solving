#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define PI 3.1415927

using namespace std;

int N;
string str;
vector<string> ans;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    for (int i = 0; i < N; i++)
    {
        cin >> str;

        if (ans.size() == 0)
        {
            ans.push_back(str);
            continue;
        }

        bool is_equal = false;
        for (int j = 0; j < ans.size(); j++)
        {
            int idx = str.find(ans[j][0]);

            while (idx != string::npos) // ans[j][0]을 찾은 경우 진행
            {
                if (str.substr(idx) == ans[j].substr(0, str.length() - idx)) // idx부터 끝까지 같은지 확인
                {
                    if (str.substr(0, idx) == ans[j].substr(str.length() - idx)) // 처음부터 idx까지 같은지 확인
                    {
                        is_equal = true;
                        break;
                    }
                }
                idx = str.find(ans[j][0], idx + 1);
            }
        }

        if (is_equal)
            continue;
        else
            ans.push_back(str);
    }

    cout << ans.size();

    return 0;
}
