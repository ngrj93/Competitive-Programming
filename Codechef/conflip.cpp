#include<iostream>
using namespace std;

int t,q,i,n,g;

int main(){
	cin>>t;
	while(t--){
		cin>>g;
		while(g--){
			cin>>i>>n>>q;
			if(n%2){
				if(i==q)
					cout<<n/2<<endl;
				else
					cout<<n/2+1<<endl;
			}
			else
				cout<<n/2<<endl;
		}
	}
	return 0;
}



