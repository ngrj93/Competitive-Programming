/*
ID: ngrj931
PROG: subset
LANG: C++11
*/

#include<iostream>
#include<fstream>
using namespace std;

int n,sum_g;
long long dp[400][40];

long long subset_sum(int sum,int k){
	if(sum<0||k<0)
		return 0;
	if(dp[sum][k]!=-1)
		return dp[sum][k];
	if(sum==0 && k==0)
		return dp[sum][k]=1;
	return dp[sum][k]=subset_sum(sum,k-1)+subset_sum(sum-k,k-1);
}

int main(){
	ofstream fout("subset.out");
	ifstream fin("subset.in");
	fin>>n;
	sum_g=n*(n+1)/2;	
	if(sum_g%2)
		fout<<0<<endl;
	else{
		for(int i=0;i<=sum_g/2;i++)
			for(int j=0;j<=n;j++)
				dp[i][j]=-1;
		long long ans=subset_sum(sum_g/2,n);
		fout<<ans/2<<endl;
	}
	return 0;
}
