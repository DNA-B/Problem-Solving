#include <bits/stdc++.h>

using namespace std;

long long arr[5][5];
long long result[5][5];
long long tmp[5][5];
long long n, b;

void pow(long long m1[5][5], long long m2[5][5])
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            tmp[i][j] = 0;
            for (int k = 0; k < n; k++)
            {
                tmp[i][j] += m1[i][k] * m2[k][j];
            }
            tmp[i][j] %= 1000;
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            m1[i][j] = tmp[i][j]; // m1은 result 혹은 arr
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> b;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
        result[i][i] = 1; // 처음에 result를 단위 행렬로 설정해놓으면 처음 곱해질때 값이 그대로 들어온다.
    }
    
    while (b > 0) // b가 1일 경우 pow(result, arr)가 실행되고 result 갱신 후 종료 
    { // result는 b가 계속 나눠지면서 1이 되면 갱신된다.
        if (b % 2 != 0) // 홀수일 때 (x^n = x^(n-1) * x)
            pow(result, arr);
        
        if (b > 1) // 쓸대없이 실행되는 경우 방지
            pow(arr, arr);
        
        b /= 2;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << result[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}