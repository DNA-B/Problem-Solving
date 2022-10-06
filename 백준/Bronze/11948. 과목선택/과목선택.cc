#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int li1[4], li2[2], sum = 0;
    for(int i=0; i<4; i++){
        cin>>li1[i];
    }
    for(int i=0; i<2; i++){
        cin>>li2[i];
    }
    
    sort(li1, li1+4);
    sort(li2, li2+2);
    
    for(int i=1; i<4; i++){
        sum += li1[i];
    }
    sum += max(li2[0], li2[1]);
    
    cout<<sum;
    return 0;
}