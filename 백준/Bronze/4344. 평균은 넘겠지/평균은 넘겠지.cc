#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int arr[1001] = { 0 };
    int sum = 0;
    double avg;
    int stu;
    int rep;
    int count = 0;
    double res;

    cin >> rep;

    while (rep--)
    {
        sum = 0;
        count = 0;

        cin >> stu;
        for (int i = 0; i < stu; i++)
        {
            cin >> arr[i];
            sum += arr[i];
        }
        avg = (double)sum / stu;
        for (int i = 0; i < stu; i++)
        {
            if (arr[i] > avg) count++;
        }
        res = ((double)count / stu) * 100;

        cout << fixed;
        cout.precision(3);
        cout << res << "%\n";
    }

    return 0;
}