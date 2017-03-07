#include<iostream>
#include<algorithm>
using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--){
		int n,l,b;
		cin>>n>>l>>b;
		while(n-- && l>=0 && b>=0){
			if(l>b)
				l-=b;
			else
				b-=l;
		}
		if(l*b!=0)
			cout<<"Yes "<<l*b<<endl;
		else
			cout<<"No "<<endl;
	}
	return 0;
}

			

