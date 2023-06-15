#include<bits/stdc++.h>
#define INF 0x3f3f3f3f

using namespace std;

int O, W, n_scenario = 1; // 적정 체중, 실제 체중
char order;
int n;
bool is_die = false;


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);



    while (1)
    {
        cin >> O >> W;

        if (O == 0 && W == 0) // 프로그램 종료
            break;

        while(1) 
        {
            cin >> order >> n;

            if (order == '#' && n == 0)
                break;

            if (is_die)
                continue;

            switch (order)
            {
            case 'F':
                W += n;
                break;
            case 'E':
                W -= n;
                break;
            }

            if (W <= 0)
                is_die = true;
        }

        if ((O / 2) < W && W < (2 * O)) // 시나리오 종료
            cout << n_scenario << " :-)\n";
        else if (W <= 0)
            cout << n_scenario << " RIP\n";
        else
            cout << n_scenario << " :-(\n";

        n_scenario++;
        is_die = false;
    }

    return 0;
}