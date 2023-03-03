#include <bits/stdc++.h>

using namespace std;

int score;
int arr[5];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cin >> score;

            switch (i)
            {
            case 0:
                arr[0] += score;
                break;
            case 1:
                arr[1] += score;
                break;
            case 2:
                arr[2] += score;
                break;
            case 3:
                arr[3] += score;
                break;
            case 4:
                arr[4] += score;
                break;
            }
        }
    }
    
    cout << (max_element(arr, arr + 5) - arr) + 1<< " " << *max_element(arr, arr + 5);

    return 0;
}