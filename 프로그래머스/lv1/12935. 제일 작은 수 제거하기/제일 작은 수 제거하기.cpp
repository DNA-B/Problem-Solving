#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> arr) {
    vector<int> answer;
    int min_idx;
    
    if(arr.size() == 1)
        answer.push_back(-1);
    else
    {
        min_idx = min_element(arr.begin(), arr.end()) - arr.begin();
        arr.erase(arr.begin() + min_idx);
        
        answer = arr;
    }
    
    return answer;
}