#include<iostream>
using namespace std;

int t,n,k;
int arr[100];

int input(){
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>arr[i];
	cin>>k;
	k--;
}

int find_position(){
	int c=0;
	for(int i=0;i<n;i++)
		if(arr[i]<arr[k])
			c++;
	cout<<c+1<<endl;
}

int main(){
	cin>>t;
	while(t--){
		input();
		find_position();
	}
	return 0;
}

