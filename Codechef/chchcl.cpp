#include<iostream>
using namespace std;

int t,n,m;

int main(){
	cin>>t;
	while(t--){
		cin>>n>>m;
		long long prod=(long long)n*m;
		if(prod%2)
			cout<<"No"<<endl;
		else
			cout<<"Yes"<<endl;
	}
	return 0;
}

	
