#include <bits/stdc++.h>

using namespace std;

vector <int> v(1000002); // 인덱스 = 표의 번호
int n;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int x;

    cin >> n;

    for (int i = 0; i < n; i++) 
    {
        // 표의 번호가 2^31 - 1이지만 n은 1000000개이다.
        // 그러므로 1~1000000까지 표가 예매되었다면 적어도 1000001번은 예매가 가능하다.
        cin >> x;
        
        // 1000000보다 큰 수는 저장할 필요가 없다.
        // 그 전에 더 작은 수가 예매 가능하기 때문이다.
        if (x <= 1000000) 
            v[x]++;
    }


    for (int i = 1; i <= 1000001; i++)
    {
        if (v[i] == 0)
        {
            cout << i;
            return 0;
        }
    }

    return 0;
}