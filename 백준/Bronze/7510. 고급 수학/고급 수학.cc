#include <bits/stdc++.h>

using namespace std;

int N;
int tri[3];
int is_ortho;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    for (int i = 1; i <= N; i++)
    {
        is_ortho = 0;

        for (int i = 0; i < 3; i++)
            cin >> tri[i];

        sort(tri, tri + 3);
        is_ortho = pow(tri[2], 2) - (pow(tri[1], 2) + pow(tri[0], 2));


        if (is_ortho == 0)
            cout << "Scenario #" << i << ":\nyes\n";
        else
            cout << "Scenario #" << i << ":\nno\n";
        cout << "\n";
    }

    return 0;
}
