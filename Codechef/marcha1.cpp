#include<iostream>
using namespace std;

int t,n,m;
int arr[20];

bool combination(int cur,int len,int sum,int index){
	if(cur==len){
		if(sum==m)
			return true;
		return false;
	}
	bool flag=false;
	for(int i=index;i<n;i++){
		bool flag=combination(cur+1,len,sum+arr[i],i+1);
		if(flag)
			return true;
	}
	return false;
}

int main(){
	cin>>t;
	while(t--){
		cin>>n>>m;
		for(int i=0;i<n;i++)
			cin>>arr[i];
		if(m==0){
			cout<<"Yes"<<endl;
			continue;
		}
		bool flag=false;
		for(int i=1;i<=n;i++){
			flag=combination(0,i,0,0);
			if(flag)
				break;
		}
		if(flag)
			cout<<"Yes"<<endl;
		else
			cout<<"No"<<endl;
	}
	return 0;
}


