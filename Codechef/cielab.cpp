#include<iostream>
using namespace std;

int main(){
	int a,b;
	cin>>a>>b;
	int diff=a-b;
	int rem=diff%10;
	if(rem==9)
		cout<<diff-1<<endl;
	else
		cout<<diff+1<<endl;
	return 0;
}

	
