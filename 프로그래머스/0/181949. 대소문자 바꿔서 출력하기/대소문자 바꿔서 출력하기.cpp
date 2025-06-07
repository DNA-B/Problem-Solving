#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int main(void) {
    string str;
    cin >> str;
    for(char ch : str)
        cout << (char)(islower(ch) ? toupper(ch) : tolower(ch));
        
    return 0;
}