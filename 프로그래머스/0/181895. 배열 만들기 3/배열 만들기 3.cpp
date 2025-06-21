#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr, vector<vector<int>> intervals) {
    vector<int> answer;
    
    for (vector<int> interval : intervals) {
        int st = interval[0];
        int en = interval[1];
        for (int i = st; i <= en; i++)
            answer.push_back(arr[i]);
    }

    return answer;
}