#include<iostream>
#include<cstring>
using namespace std;

int t,n;

int find_loop(int cur,int arr[],int visited[]){
	int it=cur-1,total=0;
	while(!visited[it]){
		visited[it]=cur;
		it=(it+1+arr[it])%n;
		total++;
	}
	int st=cur-1;	
	while(st!=it){
		total--;
		st=(st+1+arr[st])%n;
	}
	return total;
}

int main(){
	cin>>t;
	while(t--){
		cin>>n;
		int arr[n+1];
		for(int i=0;i<n;i++)
			cin>>arr[i];
		int visited[n];
		memset(visited,0,sizeof(visited));
		int total=0;
		for(int i=0;i<n;i++){
			if(!visited[i])
				total+=find_loop(i+1,arr,visited);
		}
		cout<<total<<endl;
	}
	return 0;
}
