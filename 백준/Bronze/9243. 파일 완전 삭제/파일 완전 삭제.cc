#include <bits/stdc++.h>
#define INF 0x3f3f3f3f

using namespace std;

int N;
string before_file, after_file;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    cin >> before_file >> after_file;

    while (N--)
    {
        for (int i = 0; i < before_file.length(); i++)
        {
            if (before_file[i] == '1')
                before_file[i] = '0';
            else
                before_file[i] = '1';
        }
    }

    if (before_file == after_file)
        cout << "Deletion succeeded";
    else
        cout << "Deletion failed";

    return 0;
}