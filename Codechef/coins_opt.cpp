#include<iostream>
#include<map>
#include<algorithm>
using namespace std;

map<int,int> mp;

long long findbestconversion(long long n){
	if(!mp.count(n))
		mp[n]=max(n,findbestconversion(n/2)+findbestconversion(n/3) +findbestconversion(n/4));
	else
		return mp[n];
}

int main(){
	long long n;
	mp[0]=0;
	while(cin>>n)
		cout<<findbestconversion(n)<<endl;
	return 0;
}
