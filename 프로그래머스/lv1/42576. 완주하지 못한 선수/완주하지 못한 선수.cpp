#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;


string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    map<string, int> is_completion;
    
    for(int i = 0;i<completion.size();i++)
        is_completion[completion[i]]++;
    
    for(int i = 0;i<participant.size();i++)
    {
        if(is_completion[participant[i]] > 0)
            is_completion[participant[i]]--;
        else
            answer += participant[i];
    }
    
    return answer;
}