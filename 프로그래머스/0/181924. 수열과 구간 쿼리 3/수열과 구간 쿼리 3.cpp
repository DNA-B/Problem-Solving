#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr, vector<vector<int>> queries) {
    for (vector<int> query : queries) {
        int q1 = query[0];
        int q2 = query[1];
        swap(arr[q1], arr[q2]);
    }
    
    return arr;
}