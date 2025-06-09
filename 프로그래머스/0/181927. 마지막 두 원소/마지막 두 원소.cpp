#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> num_list) {
    vector<int> answer = num_list;
    int last = num_list[num_list.size() - 1];
    int last_prev = num_list[num_list.size() - 2];
    
    if (last > last_prev)
        answer.push_back(last - last_prev);
    else
        answer.push_back(2 * last);
    
    return answer;
}