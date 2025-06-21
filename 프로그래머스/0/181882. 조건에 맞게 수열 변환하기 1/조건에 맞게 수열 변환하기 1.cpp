#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr) {
    for (int& n : arr) {
        if (n >= 50 && (n % 2 == 0))
            n /= 2;
        else if (n < 50 && (n % 2 != 0))
            n *= 2;
    }
    
    return arr;
}