#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    vector<int> one = {1,2,3,4,5}; // 5
    vector<int> two = {2,1,2,3,2,4,2,5}; // 8
    vector<int> three = {3,3,1,1,2,2,4,4,5,5}; // 10
    int max = -1;
    int o_one = 0, o_two = 0, o_three = 0;
    
    for(int i = 0; i < answers.size();i++)
    {
            if(one[i%5] == answers[i])
            {
                o_one++;
                
                if(max < o_one)
                    max = o_one;
            }
            
            if(two[i%8] == answers[i])
            {
                o_two++;
                
                if(max < o_two)
                    max = o_two;    
            }
        
            if(three[i%10] == answers[i])
            {
                o_three++;
            
                if(max < o_three)
                    max = o_three;
            }
            
    }
    
    if(max == o_one)
        answer.push_back(1);
    
    if(max == o_two)
        answer.push_back(2);
    
    if(max == o_three)
        answer.push_back(3);
    
    return answer;
}