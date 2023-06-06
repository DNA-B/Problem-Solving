#include<bits/stdc++.h>
#define INF 0x3f3f3f3f

using namespace std;

char input[5][10];
int gear[5][8];
bool is_rotate[5];
int K, N, R;
int ans = 0;

// n : 톱니
// r : 방향
void gear_rotate(int n, int r) 
{   
    if (n < 1 || n > 4)
        return;

    is_rotate[n] = true; // 이 톱니는 rotate 했다는 것을 표시

    if (n == 1) // 오른쪽만 비교
    {
        if (is_rotate[n + 1] == false) // 옆 바퀴가 돌아간 적이 없고, 극이 다르다면
        {
            if (gear[n][2] != gear[n + 1][6]) // n은 [2], 오른쪽은 [6]번 인덱스 주의
                gear_rotate(n + 1, -r);
        }
    }
    else if (n == 4) // 왼쪽만 비교
    {
        if (is_rotate[n - 1] == false) // 옆 바퀴가 돌아간 적이 없고, 극이 다르다면
        {
            if (gear[n][6] != gear[n - 1][2]) // n은 [6], 왼쪽은 [2]번 인덱스 주의
                gear_rotate(n - 1, -r);
        }
    }
    else // 양쪽 확인
    {
        if (is_rotate[n + 1] == false) // 옆 바퀴가 돌아간 적이 없고, 극이 다르다면
        {
            if (gear[n][2] != gear[n + 1][6]) // n은 [2], 오른쪽은 [6]번 인덱스 주의
                gear_rotate(n + 1, -r);
        }

        if (is_rotate[n - 1] == false) // 옆 바퀴가 돌아간 적이 없고, 극이 다르다면
        {
            if (gear[n][6] != gear[n - 1][2]) // n은 [6], 왼쪽은 [2]번 인덱스 주의
                gear_rotate(n - 1, -r);
        }
    }

    if (r == 1) // 시계
        rotate(gear[n], gear[n] + 8 - r, gear[n] + 8); 
    else if (r == -1) // 반시계
        rotate(gear[n], gear[n] - r, gear[n] + 8);
}


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    for (int i = 1; i <= 4; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            cin >> input[i][j]; // [N : 0] <--> [S : 1]
            gear[i][j] = input[i][j] - '0';
        }
    }

    cin >> K;

    while (K--)
    {
        cin >> N >> R;

        fill(is_rotate + 1, is_rotate + 5, false);
        gear_rotate(N, R);
    }

    for (int i = 1; i <= 4; i++)
    {
        if (gear[i][0] == 1) // S극이면 [ans + 2^(i-1)]
            ans += pow(2, i - 1);
    }

    cout << ans;

    return 0;
}