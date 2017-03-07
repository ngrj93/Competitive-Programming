#include<iostream>
using namespace std;

int main(){
	int x1,x2,v1,v2;
	cin>>x1>>v1>>x2>>v2;
	if(v1==v2 && x1==x2)
		cout<<"YES"<<endl;
	else if(v1==v2)
		cout<<"NO"<<endl;
	else{
		int time=(x1-x2)/(v2-v1);
		if(time>=0 && x1+time*v1==x2+time*v2)
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;
	}
	return 0;
}
