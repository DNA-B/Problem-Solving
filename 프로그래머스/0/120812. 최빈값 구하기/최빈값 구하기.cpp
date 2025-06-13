#include <string>
#include <vector>

using namespace std;

int cnt[1005];

int solution(vector<int> array) {
    int idx = -1;
    int answer = -1;
    
    for (int n : array) {
        cnt[n]++;
        if (answer < cnt[n]) {
            answer = cnt[n];
            idx = n;
        }
    }
    
    for (int i = 0; i < 1000; i++) {
        if (i != idx && cnt[i] == answer)
            return -1;
    }
    
    return idx;
}