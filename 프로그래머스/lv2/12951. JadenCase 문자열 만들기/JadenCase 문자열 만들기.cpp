#include <string>
#include <vector>

using namespace std;

string solution(string s) 
{
    string answer = "";
    
    s[0] = toupper(s[0]); 
    answer+=s[0];
    
    for(int i = 1;i<s.length();i++)
    {
        if(s[i] == ' ')
            s[i+1] = toupper(s[i+1]);
        
        if(s[i] >= 'A' && s[i] <= 'Z' && s[i-1] != ' ')
            s[i] = tolower(s[i]);
        
        answer += s[i];
    }
    
    return answer;
}