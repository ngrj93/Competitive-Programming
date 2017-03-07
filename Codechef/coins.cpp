#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#define MAX 1000007
using namespace std;

int dp[MAX];

long long FindBestConversion(int n){
	if(n>=MAX)
		return max((long long)n,(long long)FindBestConversion(n/2)+FindBestConversion(n/4)
			+FindBestConversion(n/3));
	else if(dp[n]==-1)
		dp[n]=max(n,(int)FindBestConversion(n/2)+(int)FindBestConversion(n/4)
			+(int)FindBestConversion(n/3));
	return dp[n];
}

int main(){
	int n;
	memset(dp,-1,sizeof(dp));
	dp[0]=0;dp[1]=1;
	while(cin>>n)
		printf("%lld\n",FindBestConversion(n));
	return 0;
}

//optimization would be to use a map to memoize as the input size is too large to create a complete array
