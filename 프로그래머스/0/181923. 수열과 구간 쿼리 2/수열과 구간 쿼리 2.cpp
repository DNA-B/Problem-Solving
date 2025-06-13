#include <string>
#include <vector>
#include <climits>

using namespace std;

vector<int> solution(vector<int> arr, vector<vector<int>> queries) {
    vector<int> answer;
    
    for (vector<int> query : queries) {
        int s = query[0];
        int e = query[1];
        int k = query[2];
        
        int mn = INT_MAX;
        for (int i = s; i <= e; i++) {
            if (arr[i] > k)
                mn = min(mn, arr[i]);
        }
        
        if (mn == INT_MAX)
            answer.push_back(-1);
        else
            answer.push_back(mn);
    }
    
    return answer;
}