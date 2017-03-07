#include<iostream>
#include<cstring>
using namespace std;

int main(){
	int n,k,a;
	cin>>a>>n>>k;
	while(a>0 && k--){
		cout<<a%(n+1)<<" ";
		a/=(n+1);
	}
	while(k-->0)
		cout<<0<<" ";
	return 0;
}

