#include<iostream>
using namespace std;

int n,k,q;
int input[100001];
int output[100001];

void rotate(){
	for(int i=0;i<n;i++)
		output[(i+k)%n]=input[i];
}

int main(){
	cin>>n>>k>>q;
	for(int i=0;i<n;i++)
		cin>>input[i];
	rotate();
	while(q--){
		int m;
		cin>>m;
		cout<<output[m]<<endl;
	}
	return 0;
}

