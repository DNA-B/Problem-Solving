#include <string>
#include <vector>

using namespace std;

string solution(string myString) {
    for (char& ch : myString) {
        if (ch == 'a' || ch == 'A') 
            ch = toupper(ch);
        else 
            ch = tolower(ch);
    }

    return myString;
}