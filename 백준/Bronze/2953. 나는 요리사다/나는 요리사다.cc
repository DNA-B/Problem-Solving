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
            arr[i] += score;
        }
    }
    
    cout << (max_element(arr, arr + 5) - arr) + 1<< " " << *max_element(arr, arr + 5);

    return 0;
}