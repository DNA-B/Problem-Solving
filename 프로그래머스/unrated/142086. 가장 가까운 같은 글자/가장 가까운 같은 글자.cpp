#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    vector<int> tmp(26, 0);
    int cur_idx;
    
    for(int i = 0;i<s.length();i++)
    {   
        if(tmp[s[i] - 'a']== 0)
        {
            tmp[s[i] - 'a'] = 1;
            answer.push_back(-1);
            continue;
        }
        else
        {
            for(int j = 0;j<i;j++)
            {
                if(s[j] == s[i])
                    cur_idx = j;
            }
            answer.push_back(i - cur_idx);
            cur_idx = 0;
        }
    }
    
    return answer;
}