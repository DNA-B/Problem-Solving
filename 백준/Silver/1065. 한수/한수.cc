#include <bits/stdc++.h>

using namespace std;

/*
- BOJ 1065번 : 한수
- 시간제한이 2초
- 1~N까지 반복하면서 각 수들을 string으로 변환해서 brute force
*/

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int cnt = 0;
    int n;
    int gap = 0;
    bool is_pmt = true;

    string temp;

    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        temp = to_string(i); // 한 자리 씩 비교를 위해 i를 문자열로 변환
        
        if (temp.length() <= 2) // 한 자리수와 두 자리수는 모두 한수다.
        {
            cnt++;
            continue;
        }

        for (int j = 0; j < temp.length() - 1; j++)
        {
            if (j > 0) 
            {
                if (((temp[j] - '0') - (temp[j + 1] - '0')) != gap)
                { // 만약 등차가 아니라면 false
                    is_pmt = false;
                }
            }
            gap = (temp[j] - '0') - (temp[j + 1] - '0');
        }

        if (is_pmt == true) // 등차라면 cnt++
            cnt++;
        
        is_pmt = true;
    }
    
    cout << cnt;

    return 0;
}