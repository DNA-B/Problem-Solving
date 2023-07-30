#include <bits/stdc++.h>

using namespace std;

/*
BOJ 2960 : 에라토스테네스의 체
- 이 문제는 소수까지 지워버리는 조건을 제시하였다.
- 에라토스테네스의 체는 소수를 찾기 위한 알고리즘으로 자주 쓰인다.
- 그래서 소수 index를 제외하고는 다 지워버린다.
========================================================================
- 그렇다면 만약 sqrt(N)이 반복문 i의 조건이었다면?
- 예제 입력 2 -> [15, 12]의 경우 5, 7, 11, 13이 지워지지 않는 상황이 발생한다.
- 그렇기 때문에 반복문 i의 조건을 N까지 걸어준다.
*/

int N, K;
int cnt = 0;
bool erase_num[1001];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N >> K;

    for (int i = 2; i <= N; i++)
    {
        if (erase_num[i])
            continue;

        for (int j = i; j <= N; j += i) // j = i로 하여 소수까지 지워버린다.
        {
            if (erase_num[j])
                continue;

            erase_num[j] = true;
            cnt++;

            if (cnt == K)
            {
                cout << j;
                return 0;
            }
        }
    }

    return 0;
}