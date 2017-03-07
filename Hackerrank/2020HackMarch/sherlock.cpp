#include<iostream>

using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--){
		int a,b;
		cin>>a>>b;
		int ans=0,start=1;
		while(true){
			int current=start*start;
			if(current>=a && current<=b)
				ans++;
			if(current>b)
				break;
			start++;
		}
		cout<<ans<<endl;
	}
	return 0;
}
		

