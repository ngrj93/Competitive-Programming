/*
ID: ngrj931
PROG: nocows
LANG: C++11
*/

#include<iostream>
#include<fstream>
# define MOD 9901
using namespace std;

int n,k;
int dp[100][200];

int number_of_trees(int num,int height){
	if(num<0||height<0)
		return 0;
	else if(dp[height][num]!=-1)
		return dp[height][num];
	else{
		int temp=0;
		for(int i=1;i<num-1;i+=2)
			temp=(temp+(number_of_trees(i,height-1)%MOD*(number_of_trees(num-i-1,height-1)%MOD)%MOD))%MOD;
		return dp[height][num]=temp;
	}
}

int main(){
	ofstream fout("nocows.out");
	ifstream fin("nocows.in");
	fin>>n>>k;
	for(int i=0;i<100;i++)
		for(int j=0;j<200;j++)
			dp[i][j]=-1;
	for(int i=0;i<100;i++)
		dp[i][0]=1,dp[i][1]=1;
	dp[0][1]=0;
	number_of_trees(n,k);
	number_of_trees(n,k-1);
	if(dp[k][n]-dp[k-1][n]<0)
		fout<<MOD+(dp[k][n]-dp[k-1][n])<<endl;
	else
		fout<<dp[k][n]-dp[k-1][n]<<endl;
	return 0;
}

	
