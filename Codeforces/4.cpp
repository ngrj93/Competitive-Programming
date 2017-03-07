#include<iostream>

using namespace std;

int main(){
	int n,k,i;
	cin>>n>>k;
	int arr[n];
	for(i=0;i<n;i++)
		cin>>arr[i];
	int val=arr[k-1];
	for(i=0;i<n;i++){
		if(arr[i]==0)
			break;
		else if(arr[i]<val)
			break;
	}
	cout<<i<<endl;
	return 0;
}
