#include <string>
#include <vector>

using namespace std;

int solution(vector<int> arr, int idx) {
    int answer = 0;
    
    for (int i = idx; i < arr.size(); i++) {
        if (arr[i] == 1)
            return i;
    }
    
    return -1;
}