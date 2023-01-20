#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    map<int, int> m;
    
    for(int i = 0; i<reserve.size();i++)
        m[reserve[i]] = 2;
    
    for(int i = 0; i < lost.size(); i++)
    {
        if(m.count(lost[i]) != 0)
            m[lost[i]] = 1;
        else
            m[lost[i]] = 0;
    }
    
    for(auto item : m)
    {
        if(item.second == 2)
        {
            if(m.count(item.first - 1) != 0 && m[item.first - 1] == 0)
            {
                m[item.first - 1] = 1;
                m[item.first] = 1;
                continue;
            }
            
            if(m.count(item.first + 1) != 0 && m[item.first + 1] == 0)
            {
                m[item.first + 1] = 1;
                m[item.first] = 1;
                continue;
            }
        }
    }
    
    answer = n;
    for(auto item : m)
        if(item.second == 0)
            answer--;
    
    return answer;
}