#include <bits/stdc++.h>

using namespace std;

int main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    map<int, int> m; // map의 find()는 O(log(n))이다. 
    vector<int> res;
    map<int, int>::iterator iter;
    int target;
    int n_num;
    int n_target;
    int x;
    int temp = 0;

    cin >> n_num;

    while (n_num--)
    {
        cin >> x;
        iter = m.find(x);

        if (iter == m.end()) // 중복 검사
        {
            m[x] = 1;
        }
        else
        {
            m[x] += 1;
        }
    }

    cin >> n_target;

    while (n_target--)
    {
        cin >> target;
        res.push_back(m[target]);
        // 만약 시간을 줄이고자 erase를 한다면 target이 중복되어 들어올 경우 find가 불가능해진다.
    }

    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i] << " ";
    }

    return 0;
}