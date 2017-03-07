/*
ID: ngrj931
PROG: subset
LANG: C++11
*/

#include<iostream>
#include<fstream>

using namespace std;

int n,sum_g,max_g;

int generate_combination(int cur,int l,int sum,int index){
	int max_local=0;
	if(sum>sum_g/2)
		return -1;
	if(cur==l){
		if(sum==sum_g-sum)
			return 1;
		return 0;
	}
	for(int i=index;i<=n;i++){
		int temp=generate_combination(cur+1,l,sum+i,i+1);
		if(temp==-1)
			break;
		max_local+=temp;
	}
	return max_local;
}

int main(){
	ofstream fout("subset.out");
	ifstream fin("subset.in");
	fin>>n;
	sum_g=n*(n+1)/2;
	for(int i=1;i<=n/2;i++){
		int local_max=generate_combination(0,i,0,1);
		if(i==n/2 && !(n%2))
			max_g+=local_max/2;
		else
			max_g+=local_max;
	}
	fout<<max_g<<endl;
	return 0;
}
