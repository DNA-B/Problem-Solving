#include <iostream>

using namespace std;

int main() {
	int n, a, b, s, t;
	
	cin>>n>>a>>b;
	cin>>s>>t;
	
	if(s>a && s<b && t>a && t<b)
		cout<<"City";
	else if((s<=a && t<=a) || (s>=b && t>=b))
		cout<<"Outside";
	else
		cout<<"Full";
		
	return 0;
}