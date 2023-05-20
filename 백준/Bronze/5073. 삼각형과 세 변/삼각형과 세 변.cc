#include<bits/stdc++.h>
#define INF 0x3f3f3f3f

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int arr[3];
    
    while (1)
    {
        for (int i = 0; i < 3; i++)
            cin >> arr[i];

        sort(arr, arr + 3);

        if (arr[0] == 0 && arr[1] == 0 && arr[2] == 0)
            break;

        if (arr[2] >= (arr[0] + arr[1]))
            cout << "Invalid\n";
        else if (arr[0] == arr[1] && arr[1] == arr[2])
            cout << "Equilateral\n";
        else if (arr[0] != arr[1] && arr[1] != arr[2] && arr[0] != arr[2])
            cout << "Scalene\n";
        else
            cout << "Isosceles\n";
    }

    return 0;
}