#include<bits/stdc++.h>
#define INF 0x3f3f3f3f

using namespace std;

string color[10] = { "black", "brown","red","orange","yellow","green",
                    "blue","violet","grey","white" };

long long ans = 0;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    string input_color;
    string str = "";


    for (int i = 0; i < 3; i++)
    {
        cin >> input_color;

        for (int j = 0; j < 10; j++)
        {
            if (i == 2 && color[j] == input_color)
            {
                ans = stoi(str) * pow(10, j);
                break;
            }

            if (color[j] == input_color)
                str += to_string(j);
        }
    }

    cout << ans;

    return 0;
}