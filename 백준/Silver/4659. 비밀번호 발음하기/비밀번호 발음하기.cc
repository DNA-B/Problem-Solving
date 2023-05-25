#include<bits/stdc++.h>
#define INF 0x3f3f3f3f

using namespace std;

string pwd;
int aeiou, len;
int jamo[21];
char pre, cur;
bool pass;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    
    while (true)
    {
        cin >> pwd;

        if (pwd == "end")
            break;


        fill(jamo, jamo + 21, 0); // init
        pre = '\n', cur = '\n';
        aeiou = 0, len = pwd.length();
        pass = true;

        for (int i = 0; i < len; i++)
        {
            cur = pwd[i];

            if (cur == 'a' || cur == 'e' || cur == 'i' || cur == 'o' || cur == 'u') // 모음이면 1
            {
                aeiou++;
                jamo[i] = 1;
            }
            else // 자음이면 2
            {
                jamo[i] = 2;
            }

            if (cur == pre) // 같은 글자 연속 두번
            {
                if ((cur == 'e' && pre == 'e') || (cur == 'o' && pre == 'o'))
                    continue;

                pass = false;
                break;
            }
                
            pre = cur;
        }

        for (int i = 0; i < len - 2; i++) // 자음, 모음 연속 3개
        {
            if (jamo[i] == jamo[i + 1] && jamo[i + 1] == jamo[i + 2])
            {
                pass = false;
                break;
            }
        }

        if (aeiou == 0) // 모음 0개면 false
            pass = false;

        if(pass)
            cout << "<" << pwd << "> is acceptable.\n";
        else
            cout << "<" << pwd << "> is not acceptable.\n";
    }

    return 0;
}