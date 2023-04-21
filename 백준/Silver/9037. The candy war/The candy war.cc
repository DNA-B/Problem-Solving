#include<bits/stdc++.h>

using namespace std;

int T, N;
int cycle;
int arr[11];
int tmp[11];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> T;

    while (T--)
    {
        cin >> N;

        cycle = 0;

        for (int i = 0; i < N; i++)
        {
            cin >> arr[i];
            
            if (arr[i] % 2 != 0)
                arr[i] += 1;
        }

        while (!equal(arr + 1, arr + N, arr))
        {
            for (int i = 0; i < N; i++)
            { // 모든 아이들이 "동시에" 오른쪽으로 사탕 전달
                tmp[(i + 1) % N] = arr[i % N] / 2;
                arr[i % N] -= arr[i % N] / 2;
            }

            for (int i = 0; i < N; i++)
                arr[i] += tmp[i]; // 저장해둔 (candy / 2) 더하는 작업

            for (int i = 0; i < N; i++)
            { // 홀수개 가진 학생 확인
                if (arr[i] % 2 != 0)
                    arr[i] += 1;
            }

            cycle++;
        }

        cout << cycle << "\n";
    }


    return 0;
}