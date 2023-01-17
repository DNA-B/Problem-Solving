#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer;
    stack<pair<int, int>> st;
    
    answer.resize(prices.size());
    
    for(int i = 1; i <= prices.size();i++)
    {
        if(st.empty())
            st.push({prices[i-1], i});
        
        if(st.top().first > prices[i-1]) // 가격 떨어짐
        {
            while(!st.empty() && st.top().first > prices[i-1])
            {
                answer[st.top().second - 1] = i - (st.top().second); // 현재 초 - 가격 하락 전 초
                st.pop();   
            }
            
            st.push({prices[i-1], i});
        }
        else
            st.push({prices[i-1], i});
    }     
    
    while(!st.empty()) // 여기까지 왔는데 남아있으면 가격하락된 적이 없는 것들
    {
            answer[st.top().second - 1] = prices.size() - st.top().second;
            st.pop();
    }
    
    return answer;
}