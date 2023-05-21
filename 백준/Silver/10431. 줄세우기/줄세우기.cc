#include<bits/stdc++.h>
#define INF 0x3f3f3f3f

using namespace std;

int P, N;
int num[21];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> P;

    while (P--) 
    {
        int sum = 0;
        cin >> N;

        for (int i = 0; i < 20; i++) 
            cin >> num[i];
        
        for (int i = 1; i < 20; i++) 
        {
            for (int j = 0; j < i; j++) 
            {
                if (num[j] > num[i])
                    sum++;
            }
        }
        cout << N << " " << sum << "\n";
    }
    return 0;
}