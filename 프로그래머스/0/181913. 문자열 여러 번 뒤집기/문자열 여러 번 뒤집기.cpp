#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string my_string, vector<vector<int>> queries) {
    for (vector<int> query : queries) {
        int s = query[0];
        int e = query[1] + 1;
        reverse(my_string.begin() + s, my_string.begin() + e);
    }
    
    return my_string;
}