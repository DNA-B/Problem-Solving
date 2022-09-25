#include <string>
#include <iostream>
using namespace std;

bool solution(string s)
{
    bool answer = true;
    int count_p = 0;
    int count_y = 0;
    
    for(int i = 0 ; i < s.length() ; i++)
    {
        s[i] = tolower(s[i]);
        
        switch(s[i])
        {
            case 'p':
                count_p++;
                break;
            case 'y':
                count_y++;
                break;
        }
    }
    
    if(count_p != count_y)
    {
        answer = false;
    }
    
    return answer;
}