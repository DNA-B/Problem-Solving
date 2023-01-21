#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = 0;
    char ch = s[0];
    int same = 1, no_same = 0;
    
    
    
    for(int i = 1; i < s.length();i++)
    {
        if(no_same == same)
        {
            answer++;
            ch = s[i];
            same = 1;
            no_same = 0;
            continue;
        }
        
        if(s[i] != ch)
            no_same++;
        else
            same++;
    }
    
    return answer + 1;
}