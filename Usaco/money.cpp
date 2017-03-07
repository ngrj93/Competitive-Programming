/*
ID: ngrj931
PROG: money
LANG: C++11
*/

#include<iostream>
#include<fstream>

using namespace std;

ofstream fout("money.out");
ifstream fin("money.in");
int v,n;
int coin[25];
long long state[10005][26];

long long number_of_ways(int sum,int cur){
	if(sum<0||cur>=v)
		return 0;
	if(state[sum][cur]!=-1)
		return state[sum][cur];
	else
		return state[sum][cur]=number_of_ways(sum-coin[cur],cur)+number_of_ways(sum,cur+1);
}

int main(){
	fin>>v>>n;
	for(int i=0;i<v;i++)
		fin>>coin[i];
	for(int i=0;i<10005;i++)
		for(int j=0;j<26;j++)
			state[i][j]=-1;
	for(int i=0;i<v;i++)
		state[0][i]=1;
	fout<<number_of_ways(n,0)<<endl;
	return 0;
}


