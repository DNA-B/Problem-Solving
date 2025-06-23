#include <string>
#include <vector>

using namespace std;

string solution(string myString) {
    for (char& ch : myString)
        ch = toupper(ch);
    
    return myString;
}