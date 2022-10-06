#include <bits/stdc++.h>
using namespace std;


int main()
{
  double a;
    
  while(1)
  {
    cin >> a;
      
    if(a == 0) break;
      
    printf("%.2f\n", 1 + a + pow(a,2) + pow(a,3) + pow(a,4));
  }
}