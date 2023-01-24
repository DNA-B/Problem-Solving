#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

string solution(string X, string Y) {
    string answer = "";
    map<char, int> m;
    
    for(int i =0; i<X.length();i++)
        m[X[i]]++;
    
    for(int i =0; i<Y.length();i++)
    {
        if(m[Y[i]] != 0)
        {
            m[Y[i]]--;
            answer += Y[i];
        }
    }
    
    sort(answer.begin(), answer.end(), greater<char>());
    
    if(answer[0] == '0')
        answer = "0";
    else if(answer.length() == 0)
        answer = "-1";
        
    return answer;
}