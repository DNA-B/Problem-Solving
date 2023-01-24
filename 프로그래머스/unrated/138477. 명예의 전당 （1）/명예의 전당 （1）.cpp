#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(int k, vector<int> score) {
    vector<int> answer;
    vector<int> mj;
    int cur_min = 10000;
    
    for(int i = 0;i<score.size();i++)
    {
        if(mj.size() == k)
        {
            if(score[i] > *min_element(mj.begin(),mj.end()))
            {  
               mj[min_element(mj.begin(), mj.end()) - mj.begin()] = score[i];
            }
        }
        else
        {
            mj.push_back(score[i]);
        }
        
        answer.push_back(*min_element(mj.begin(), mj.end()));
    }
    
    
    return answer;
}