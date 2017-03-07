// Theatre Square 
#include<iostream>
#include<cmath>

using namespace std;

int main(){
	long long n,m,a;
	cin>>n>>m>>a;
	long long height=ceil((double)n/a);
	long long width=ceil((double)m/a);
	long long ans=height*width;
	cout<<ans<<endl;
	return 0;
}



