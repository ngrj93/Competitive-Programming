#include<iostream>
#include<climits>
using namespace std;

int main(){
	int t,n;
	cin>>t;
	while(t--){
		cin>>n;
		int arr[n+1],least_negative=INT_MIN;
		long long forward[n+1],reverse[n+1];
		bool flag=true,flag2=true;
		for(int i=1;i<=n;i++){
			cin>>arr[i];
			if(arr[i]>=0)
				flag=false;
			if(arr[i]<0){
				flag2=false;
				least_negative=arr[i]>least_negative?arr[i]:least_negative;
			}
		}
		long long currentsum=arr[1];
		if(currentsum<0)
			currentsum=0;
		forward[1]=currentsum;
		for(int i=2;i<=n;i++){
			currentsum+=arr[i];
			if(currentsum<0)
				currentsum=0;
			forward[i]=currentsum;
		}
		currentsum=arr[n];
		if(currentsum<0)
			currentsum=0;
		reverse[n]=currentsum;
		for(int i=n-1;i>=1;i--){
			currentsum+=arr[i];
			if(currentsum<0)
				currentsum=0;
			reverse[i]=currentsum;
		}
		if(flag)
			cout<<least_negative<<endl;
		else if(flag2)
			cout<<forward[n]<<endl;
		else{
			long long bestsum=0;
			for(int i=1;i<=n;i++){
				if(arr[i]<0){
					long long temp=(i-1>=1?forward[i-1]:0)+(i+1<=n?reverse[i+1]:0);
					bestsum=bestsum<temp?temp:bestsum;
				}
			}
			cout<<bestsum<<endl;
		}
	}
	return 0;
}
