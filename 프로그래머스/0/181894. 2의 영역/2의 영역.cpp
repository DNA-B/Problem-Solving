#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr) {
    vector<int> answer;
    vector<int> ids;
    
    for (int i = 0; i < arr.size(); i++)
        if (arr[i] == 2) ids.push_back(i);
    
    if (ids.empty())
        return { -1 };
    
    for (int i = ids.front(); i <= ids.back(); i++) {
        answer.push_back(arr[i]);
    }
        
    return answer;
}