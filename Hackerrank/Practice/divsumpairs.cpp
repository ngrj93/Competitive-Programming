#include<iostream>
using namespace std;

int main(){
	int n,k,count=0;
	cin>>n>>k;
	int arr[n];
	for(int i=0;i<n;i++)
		cin>>arr[i];
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			if(!((i+j)%k))
				count++;
		}
	}
	cout<<count<<endl;
	return 0;
}

