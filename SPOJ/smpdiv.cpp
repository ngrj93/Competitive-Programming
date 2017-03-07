#include<iostream>
using namespace std;

int main(){
	int t,n,x,y;
	cin>>t;
	while(t--){
		cin>>n>>x>>y;
		for(int i=1;i<n;i++){
			if(!(i%x) && (i%y))
				cout<<i<<" ";
		}
		cout<<endl;
	}
	return 0;
}
	
