#include<iostream>
#include<algorithm>
#include<climits>
using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int arr[n];
		for(int i=0;i<n;i++)
			cin>>arr[i];
		sort(arr,arr+n);
		int minimum=INT_MAX;
		for(int i=0;i<n-1;i++)
			minimum=minimum<arr[i+1]-arr[i]?minimum:arr[i+1]-arr[i];
		cout<<minimum<<endl;
	}
	return 0;
}

