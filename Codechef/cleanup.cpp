#include<iostream>
#include<algorithm>
using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--){
		int n,m,temp;
		cin>>n>>m;
		bool tasks[1001]={0};
		for(int i=0;i<m;i++){
			cin>>temp;
			tasks[temp]=true;
		}
		bool flag=true;
		for(int i=1;i<=n;i++){
			if(tasks[i]==false){
				if(flag==true){
					cout<<i<<" ";
					flag=false;
					tasks[i]=true;
				}
				else
					flag=true;
			}
		}
		cout<<endl;
		for(int i=1;i<=n;i++){
			if(tasks[i]==false)
				cout<<i<<" ";
		}
		cout<<endl;
	}
	return 0;
}

